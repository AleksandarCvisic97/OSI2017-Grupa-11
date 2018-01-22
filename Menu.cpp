#include "Menu.h"
#include <iostream>
#include <Windows.h>

using std::cout;
using std::endl;


void print_main_menu()
{
	// Glavni meni
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "================================================" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "                    SCA 2017                    " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "================================================" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "                   Administrator                " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "================================================" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "                    Analiticar                  " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "================================================" << endl;
	cout << "Pregled svih podataka za odredjenog kupca----(1)" << endl;
	cout << "Pregled svih podataka za odredjeni mjesec----(2)" << endl;
	cout << "Pregled svih podataka za odredjeni proizvod--(3)" << endl;
	cout << "Odjavi se------------------------------------(4)" << endl;
	cout << "================================================" << endl;
}