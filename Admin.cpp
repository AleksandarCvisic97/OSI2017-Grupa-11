#include "Admin.h"

void Admin::write_code(std::ofstream &stream)
{
	stream << code;
}

Admin::Admin(const std::string name, const std::string surname, const std::string username, const int pin, const int status) : User(name, surname, username, pin, status) {}
