#include "Analyst.h"
#include <iostream>

void Analyst::write_code(std::ofstream &stream)
{
	stream << code;
}

Analyst::Analyst(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : User(name, surname, username, pin, status) {}
