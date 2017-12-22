#include "Analyst.h"
#include <iostream>

void Analyst::write_code(std::ofstream &stream) const
{
	stream << code;
}

void Analyst::print_code(std::ostream &stream) const
{
	stream << code;
}

Analyst::Analyst(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : User(name, surname, username, pin, status) {}

int Analyst::get_code() const
{
	return code;
}
