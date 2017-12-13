#include "Admin.h"
#include <iostream>

void Admin::write(std::ofstream& users)
{
	if (users.is_open())
	{
		users << code << " ";
		User::write(users);
		users.close();
	}
	else std::cout << "Greska pri otvaranju datoteke: 'users.txt'";
}
