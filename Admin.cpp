#include "Admin.h"
#include "Analyst.h"
#include "Menu.h"
#include <iostream>
#include <vector>


void Admin::write_code(std::ofstream &stream) const
{
	stream << code;
}

void Admin::print_code(std::ostream &stream) const
{
	stream << code;
}

Admin::Admin(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : User(name, surname, username, pin, status) {}

int Admin::get_code() const
{
	return code;
}

void Admin::ApproveRegRequest() // Funkcija za odobravanje zahtjeva
{
	int c;
	std::string name, surname, username, pin;
	int status, code;
	std::fstream requests;
	requests.open("Requests.txt", std::ios::in);
	if (requests.is_open())
	{
		while (requests >> name >> surname >> username >> pin >> status >> code)
		{
			std::cout << name << " " << surname << " " << username << " " << pin << " " << status << " " << code << " " << std::endl;
			if (code == 0)
				std::cout << "(Administrator)" << std::endl;
			else
				std::cout << "(Analiticar)" << std::endl;
			do
			{
				std::cout << "Odobri zahtjev: DA - pritisni 1, NE - pritisni 0" << std::endl;
				std::cin >> c;
				if (c < 0 || c>1)
					std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
			} while (c < 0 || c>1);
			if (c)
			{
				if (!code)
				{
					Admin ad(name, surname, username, pin, status);
					if (registername(username))
					{
						ad.changeStatus();
						ad.write();
						std::cout << "Zahtjev je odobren." << std::endl;
					}
					else
						std::cout << "Korisnicko ime je zauzeto, nije moguce odobriti zahtjev." << std::endl;
				}
				else
				{
					Analyst an(name, surname, username, pin, status);
					if (registername(username))
					{
						an.changeStatus();
						an.write();
						std::cout << "Zahtjev je odobren." << std::endl;
					}
					else
						std::cout << "Korisnicko ime je zauzeto, nije moguce odobriti zahtjev." << std::endl;
				}
			}
		}
		std::cout << "Nema vise zahtjeva za registraciju." << std::endl;
	}
	else
		std::cout << "Greska pri otvaranju datoteke 'Requests.txt'" << std::endl;
	requests.close();
	requests.open("Requests.txt", std::ios::out);
	requests.close();
}

void Admin::AddAccount() // Funkcija za dodavanje  naloga od strane administratora
{
	std::string name, surname, username, pin;
	int status, code;

	std::cout << "Unesite podatke o korisniku " << std::endl;
	std::cout << " Ime: "; std::cin >> name;
	std::cout << " Prezime: "; std::cin >> surname;
	do
	{
		std::cout << " Korisnicko ime: ";
		std::cin >> username;

		if (!registername(username))
		{
			std::cout << "Korisnicko ime je zauzeto! Pokusajte ponovo." << std::endl;
		}
	} while (!registername(username));
	
	std::cout << " PIN(4 cifre): "; std::cin >> pin;
	
	do
	{
		std::cout << " Dodaj kao Administratora (pritisni 0) ili kao Analiticara (pritisni 1): ";
		std::cin >> code;

		if (code < 0 || code > 1)
		{
			std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
		}
	} while (code < 0 || code>1);

	status = 1;

	if (code == 0)
	{
		Admin ad(name, surname, username, pin, status);
		ad.write();
	}
	else
	{
		Analyst an(name, surname, username, pin, status);
		an.write();
	}
}

void Admin::DeleteAccount() // Funkcija za deaktivaciju naloga od strane administratora
{
	struct temp // Pomocna struktura
	{
		std::string name,surname,username,pass;
		int status, code;
		temp(std::string a="",std::string b="",std::string c="",std::string d="",int e=0,int f=0) : name(a),surname(b),username(c),pass(d),status(e),code(f) {}
	};
	int n=0, j = 0;
	std::vector<temp> arr; // Pomocni niz
	arr.reserve(50);
	temp user;
	std::string uname;
	std::cout << "Unesite korisnicko ime naloga koji zelite deaktivirati: " << std::endl;
	std::cin >> uname; // Trazeni nalog za deaktivaciju
	std::fstream users;
	users.open("Users.txt", std::ios::in);
	if (users.is_open())
	{
		while (users >> user.name >> user.surname >> user.username >> user.pass >> user.status >> user.code)
		{
			if (((user.username).compare(uname) == 0) && (user.username.compare("sca"))) // Ako je pronadjen nalog mijenja se status iz aktivnog u neaktivni
			{
				user.status = 0;
				j = 1;
			}
			arr.push_back(temp(user.name, user.surname, user.username, user.pass, user.status, user.code));
		}
		users.close();
	}
	else
		std::cout << "Greska pri otvaranju datoteke 'Users.txt'" << std::endl;
	if (j == 0)
		std::cout << "Deaktiviranje naloga nije uspjelo, jer ne postoji korisnik sa korisnickim imenom '" << uname << "'" << std::endl;
	else
	{
		users.open("Users.txt", std::ios::out);
		if (users.is_open()) // Upisivasnje nazad u fajl sa deaktiviranim nalogom
		{
			for (j = 0; j < (int)arr.size(); j++)
				users << arr[j].name << " " << arr[j].surname << " " << arr[j].username << " " << arr[j].pass << " " << arr[j].status << " " << arr[j].code << std::endl;
			users.close();
		}
		std::cout << "Nalog je uspjesno deaktiviran." << std::endl;
	}
}

int Admin::AdminMenuOptions() // Meni za administratora
{
	char c;
	do
	{
		print_admin_menu();
		std::cin >> c;
		switch (c)
		{
		case '1': ApproveRegRequest(); break;
		case '2': AddAccount(); break;
		case '3': DeleteAccount(); break;
		// Slucaj 4 za primjenu valute sistema nije jos spreman za koristenje
		case '5': std::cout << "Dovidjenja!" << std::endl; return 0; break;
		default: std::cout << "Nepostojeca opcija! Pokusajte ponovo" << std::endl; break;
		}
	} while (true);
}