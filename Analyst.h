#pragma once
#include "User.h"

class Analyst : public User
{
	const int code = 1; //code 1 == analyst
	void write_code(std::ofstream&) const override final;
	void print_code(std::ostream&) const override final;
public:
	Analyst(const std::string, const std::string, const std::string, const std::string, const int);
	int get_code() const override final;
};

