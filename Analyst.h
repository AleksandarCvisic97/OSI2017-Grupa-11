#pragma once
#include "User.h"
class Analyst : public User
{
	const int code = 1;
public:
	void write(std::ofstream&);
};

