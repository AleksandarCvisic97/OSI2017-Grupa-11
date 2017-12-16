#include "User.h"
#include <iostream>

User::User(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : name(name), surname(surname), username(username), pin(pin), status(status) {}

void User::write()
{
	std::ofstream users;
	users.open("Users.txt", std::ios::app); //prava putanja: ...\programdata\Users.txt
	if (users.is_open())
	{
		users << name << " " << surname << " " << username << " " << pin << " " << status << " ";
		write_code(users);
		users << std::endl;
		users.close();
	}
	else
		std::cout << "Greska pri otvaranju datoteke: 'Users.txt'";
}

