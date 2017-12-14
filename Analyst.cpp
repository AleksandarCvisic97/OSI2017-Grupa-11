#include "Analyst.h"
#include <iostream>

void Analyst::write_code(std::ofstream &stream)
{
	stream << code;
}

Analyst::Analyst(const std::string name, const std::string surname, const std::string username, const int pin, const int status, const int code) : User(name, surname, username, pin, status), code(code) {}
