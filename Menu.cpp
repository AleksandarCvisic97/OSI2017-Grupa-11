#include "Menu.h"
#include <iostream>

using std::cout;
using std::endl;


void print_main_menu()
{
	// Glavni meni
	cout << "================================================" << endl;
	cout << "                    SCA 2017                    " << endl;
	cout << "================================================" << endl;
	cout << "Prijava na sistem----------------------------(1)" << endl;
	cout << "Registracija---------------------------------(2)" << endl;
	cout << "Deaktivacija naloga--------------------------(3)" << endl;
	cout << "Napusti program------------------------------(4)" << endl;
	cout << "================================================" << endl;
}

void print_admin_menu()
{
	//Meni za administratora
	cout << "================================================" << endl;
	cout << "                   Administrator                " << endl;
	cout << "================================================" << endl;
	cout << "Pregledaj zahtjeve za registraciju-----------(1)" << endl;
	cout << "Dodaj nalog----------------------------------(2)" << endl;
	cout << "Deaktiviraj nalog----------------------------(3)" << endl;
	cout << "Promjena valute sistema----------------------(4)" << endl;
	cout << "Odjavi se------------------------------------(5)" << endl;
	cout << "================================================" << endl;
}

void print_analyst_menu()
{
	//Meni za analiticara
	cout << "================================================" << endl;
	cout << "                    Analiticar                  " << endl;
	cout << "================================================" << endl;
	cout << "Pregled svih podataka za odredjenog kupca----(1)" << endl;
	cout << "Pregled svih podataka za odredjeni mjesec----(2)" << endl;
	cout << "Pregled svih podataka za odredjeni proizvod--(3)" << endl;
	cout << "Odjavi se------------------------------------(4)" << endl;
	cout << "================================================" << endl;
}