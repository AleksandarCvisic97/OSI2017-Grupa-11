#pragma once
#include <string>
#include <fstream>

class User
{
protected:
	std::string name, surname, username;
	int pin;
public:
	User(std::string, std::string, std::string, int);
	void write(std::ofstream);
};

