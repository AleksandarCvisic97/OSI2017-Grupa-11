#include "Admin.h"
#include "Analyst.h"
#include "Menu.h"
#include <iostream>


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
	std::string ime, prezime, krime, pas;
	int stat, kod;
	std::fstream requests;
	requests.open("Requests.txt", std::ios::in);
	if (requests.is_open())
	{
		while (requests >> ime >> prezime >> krime >> pas >> stat >> kod)
		{
			std::cout << ime << " " << prezime << " " << krime << " " << pas << " " << stat << " " << kod << " " << std::endl;
			do
			{
				std::cout << "Odobri zahtjev: DA - pritisni 1, NE - pritisni 0" << std::endl;
				std::cin >> c;
				if (c < 0 || c>1)
					std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
			} while (c < 0 || c>1);
			if (c)
			{
				if (!kod)
				{
					Admin ad(ime, prezime, krime, pas, stat);
					if (registername(krime))
					{
						ad.changeStatus();
						ad.write();
					}
				}
				else
				{
					Analyst an(ime, prezime, krime, pas, stat);
					if (registername(krime))
					{
						an.changeStatus();
						an.write();
					}
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
	std::string ime, prezime, krime, pas;
	int stat, kod;

	std::cout << "Unesite podatke o korisniku " << std::endl;
	std::cout << " Ime: "; std::cin >> ime;
	std::cout << " Prezime: "; std::cin >> prezime;
	do
	{
		std::cout << " Korisnicko ime: ";
		std::cin >> krime;

		if (!registername(krime))
		{
			std::cout << "Korisnicko ime je zauzeto! Pokusajte ponovo." << std::endl;
		}
	} while (!registername(krime));
	
	std::cout << " PIN(4 cifre): "; std::cin >> pas;
	
	do
	{
		std::cout << " Dodaj kao Administratora (pritisni 0) ili kao Analiticara (pritisni 1): ";
		std::cin >> kod;

		if (kod < 0 || kod > 1)
		{
			std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
		}
	} while (kod < 0 || kod>1);

	stat = 1;

	if (kod == 0)
	{
		Admin ad(ime, prezime, krime, pas, stat);
		ad.write();
	}
	else
	{
		Analyst an(ime, prezime, krime, pas, stat);
		an.write();
	}
}

void Admin::DeleteAccount() // Funkcija za deaktivaciju naloga od strane administratora
{
	struct temp
	{
		std::string ime, prezime, krime, pas;
		int stat, kod;
	};
	int n = 0, j = 0, c = 10;
	struct temp *niz, korisnik;
	niz = new struct temp[c];
	std::string korIme;
	std::cout << "Unesite korisnicko ime naloga koji zelite deaktivirati: " << std::endl;
	std::cin >> korIme;
	std::fstream users;
	users.open("Users.txt", std::ios::in);
	if (users.is_open())
	{
		while (users >> korisnik.ime >> korisnik.prezime >> korisnik.krime >> korisnik.pas >> korisnik.stat >> korisnik.kod)
		{

			if (n == c)
				niz = new struct temp[c *= 2];
			if (((korisnik.krime).compare(korIme) == 0) && (korisnik.krime.compare("sca")))
			{
				korisnik.stat = 0;
				j = 1;
			}
			niz[n++] = korisnik;
		}
		users.close();
	}
	else
		std::cout << "Greska pri otvaranju datoteke 'Users.txt'" << std::endl;
	
	if (j == 0)
		std::cout << "Deaktiviranje naloga nije uspjelo, jer ne postoji korisnik sa korisnickim imenom '" << korIme << "'" << std::endl;
	
	else
	{
		
		users.open("Users.txt", std::ios::out);

		if (users.is_open())
		{
			for (j = 0; j < n; j++)
				users << niz[j].ime << " " << niz[j].prezime << " " << niz[j].krime << " " << niz[j].pas << " " << niz[j].stat << " " << niz[j].kod << std::endl;
			users.close();
		}
		std::cout << "Nalog je uspjesno deaktiviran." << std::endl;

	}


	delete[] niz;
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