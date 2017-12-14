#include "User.h"
#include <iostream>

User::User(const std::string name, const std::string surname, const std::string username, const int pin, const int status) : name(name), surname(surname), username(username), pin(pin), status(status) {}

void User::write()
{
	std::ofstream users;
	users.open("Users.txt", std::ios::app); //prava putanja: ...\programdata\Users.txt
	if (users.is_open())
	{
		users << name << " " << surname << " " << username << " " << pin << status << std::endl;
		write_code(users);
		users.close();
	}
	else
		std::cout << "Greska pri otvaranju datoteke: 'users.txt'";
}

