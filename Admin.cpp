#include "Admin.h"
#include <iostream>

void Admin::write()
{
	std::ofstream users;
	if (users.is_open())
	{
		users << code << " ";
		User::write(users);
		users.close(); //test
	}
	else std::cout << "Greska pri otvaranju datoteke: 'users.txt'";
}
