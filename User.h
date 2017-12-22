#pragma once
#include <string>
#include <fstream>

class User
{
protected:
	std::string name, surname, username, pin;
	int status; //status 1 == activated, 0 == deactivated
	virtual void write_code(std::ofstream&) const = 0;
	virtual void print_code(std::ostream&) const = 0;
	friend std::ostream& operator<<(std::ostream&, const User&);
public:
	User(const std::string, const std::string, const std::string, const std::string, const int);
	void write();
	virtual int get_code() const = 0;
	void LogIn();
	void PlaceRequest();
	void changeStatus();
	int registername(std::string new_username);
};