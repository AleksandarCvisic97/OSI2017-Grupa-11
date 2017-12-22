#pragma once
#include "User.h"

class Admin : public User
{
	const int code = 0; //code 0 == admin
	void write_code(std::ofstream&) const override final;
	void print_code(std::ostream&) const override final;
public:
	Admin(const std::string, const std::string, const std::string, const std::string, const int);
	int get_code() const override final;
	void ApproveRegRequest();
};
