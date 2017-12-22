#include <iostream>
#include "Admin.h"
#include "Menu.h"

int main()
{
	int p = 0;
	Admin fake("Petar", "Petrovic", "pero", "1234", 1);
	do
	{
		print_main_menu();
		std::cin >> p;
		switch (p)
		{
		case 1: fake.LogIn(); if (fake.get_code() == 0) print_admin_menu(); else print_analyst_menu(); break;
		case 2: fake.PlaceRequest(); break;
		case 3: std::cout << "Dovidjenja!" << std::endl; return 0; break;
		case 4: print_request_menu(); fake.ApproveRegRequest(); break;
		default: std::cout << "Nepostojeca opcija! Pokusajte ponovo" << std::endl; break;
		}
	} while (true);
}