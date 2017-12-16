#pragma once
#include <string>
#include <fstream>

class User
{
protected:
	std::string name, surname, username, pin;
	int status; //status 1 == activated, 0 == deactivated
	virtual void write_code(std::ofstream&) = 0;
public:
	User(const std::string, const std::string, const std::string, const std::string, const int);
	void write();
};


