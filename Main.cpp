#include <iostream>
#include "Admin.h"
#include "Menu.h"
#include "Analyst.h"
#include <Windows.h>

int main()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	char c;
	Admin fake("Default", "Admin", "sca", "1234", 1); // Nalog administratora za projektante sistema
	
	while(true)
	{
		print_main_menu();
		std::cin >> c;
		switch (c)
		{
		case '1': fake.LogIn(); break;
		case '2': fake.PlaceRequest(); break;
		case '3': fake.Deactivate(); break;
		case '4': std::cout << "Dovidjenja!" << std::endl; return 0; break;
		default: SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
				 std::cout << "Nepostojeca opcija! Pokusajte ponovo" << std::endl;
				 SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); break;
		}
	}

	return 0;
}