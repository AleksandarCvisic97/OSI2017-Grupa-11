#include "User.h"
#include <iostream>

User::User(std::string name, std::string surname, std::string username, int pin) : name(name), surname(surname), username(username), pin(pin) {}

void User::write(std::ofstream& users)
{
	users << name << " " << surname << " " << username << " " << pin << std::endl;
}

