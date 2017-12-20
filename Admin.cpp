#include "Admin.h"
#include "Analyst.h"
#include <iostream>


void Admin::write_code(std::ofstream &stream)
{
	stream << code;
}

Admin::Admin(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : User(name, surname, username, pin, status) {}

void Admin::ApproveRegRequest()
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