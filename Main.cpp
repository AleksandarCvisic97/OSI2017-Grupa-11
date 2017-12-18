#include <iostream>
#include "Admin.h"

int main()
{
	int p = 0, k = 0;
	Admin fake("Petar", "Petrovic", "pero", "1234", 1);
	std::cout << "==========Dobro dosli u SCA2017!==========" << std::endl << std::endl;
	while (!k)
	{
		std::cout << "(1) Prijava na sistem" << std::endl << "(2) Registruj se" << std::endl << "(3) Napusti program" << std::endl << "(4) Simulacija odobravanja naloga (admin-meni)" << std::endl;
		std::cout << "Vas izbor: "; std::cin >> p;
		if (p == 1)
		{
			k = 1;
			fake.LogIn();
		}
		else if (p == 2)
		{
			k = 1;
			fake.PlaceRequest();
		}
		else if (p == 3)
		{
			std::cout << "Dovidjenja!" << std::endl;
			return 0;
		}
		else if (p == 4)
		{
			k = 1;
			std::cout << "Prikazuje se opcija za odobravanje naloga iz menija za administratora. (test)" << std::endl << std::endl;
			fake.ApproveRegRequest();
			std::cout << "Test verzija odobravanja zavrsena." << std::endl;
		}
		else
			std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
	}
	std::cout << "Dovidjenja!" << std::endl;
	getchar();
	getchar();
	return 0;
}