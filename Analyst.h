#pragma once
#include "user.h"

class Analyst : public User
{
	const int code = 1; //code 1 == analyst
	void write_code(std::ofstream&) override final;
public:
	Analyst(const std::string, const std::string, const std::string, const std::string, const int);
};

