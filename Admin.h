#pragma once
#include "user.h"

class Admin : public User
{
	const int code = 0; //code 0 == admin
	void write_code(std::ofstream&) override final;
public:
	Admin(const std::string, const std::string, const std::string, const std::string, const int);
	void ApproveRegRequest();
};



