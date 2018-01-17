#include "Analyst.h"
#include "Menu.h"
#include <iostream>

void Analyst::write_code(std::ofstream &stream) const
{
	stream << code;
}

void Analyst::print_code(std::ostream &stream) const
{
	stream << code;
}

Analyst::Analyst(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : User(name, surname, username, pin, status) {}

int Analyst::get_code() const
{
	return code;
}

int Analyst::AnalystMenuOptions() // Meni za analititcara
{
	// Implementirati funkcije za otvaranje racuna
	
	// Implementirati funkcije sa ocitavanje podataka sa racuna i skladistenje


	char c;
	do
	{
		print_analyst_menu();
		std::cin >> c;
		switch (c)
		{
		case '1': std::cout << "Podaci za jednog kupca:" << std::endl; break; // Dodati funkciju za prikaz podataka za jednog kupca
		case '2': std::cout << "Podaci za jedan mjesec:" << std::endl; break; // Dodati funkciju za prikaz podataka za jedan mjesec
		case '3': std::cout << "Podaci za jedan prizvod:" << std::endl; break; //Dodati funkciju za prikaz podataka za jedan proizvod
		case '4': std::cout << "Dovidjenja!" << std::endl; return 0; break;
		default: std::cout << "Nepostojeca opcija! Pokusajte ponovo" << std::endl; break;
		}
	} while (true);
}