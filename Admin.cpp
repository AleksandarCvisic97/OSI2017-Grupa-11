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

void Admin::AddAccount() // Funkcija treba da rucno doda nalog
{
	
}

void Admin::DeleteAccount() // Funkcija treba da rucno deaktivira nalog
{
	
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