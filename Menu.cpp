#include "Menu.h"
#include <iostream>

using std::cout;
using std::endl;


void print_main_menu()
{
	cout << "================================================" << endl;
	cout << "                    SCA 2017                    " << endl;
	cout << "================================================" << endl;
	cout << "Prijava na sistem----------------------------(1)" << endl;
	cout << "Registracija---------------------------------(2)" << endl;
	cout << "Napusti program------------------------------(3)" << endl;
	cout << "Simulacija odobravanja naloga (admin-meni)---(4)" << endl;
	cout << "================================================" << endl;
}

void print_request_menu()
{
	cout << "================================================" << endl;
	cout << "                Odobravanje naloga              " << endl;
	cout << "================================================" << endl;
}

void print_admin_menu()
{
	//Meni za administratora
	cout << "================================================" << endl;
	cout << "                   Administrator                " << endl;
	cout << "================================================" << endl;
}

void print_analyst_menu()
{
	//Meni za analiticara
	cout << "================================================" << endl;
	cout << "                    Analiticar                  " << endl;
	cout << "================================================" << endl;
}