#include <iostream>
#include "Account.h"

void SaveAccount_Analyst(Analyst Acc)
{
	std::ofstream users;
	users.open("Users.txt", std::ios::app);
	Acc.write(users);
}

void SaveAccount_Admin(Admin Acc)
{
	std::ofstream users;
	users.open("Users.txt", std::ios::app);
	Acc.write(users);
}