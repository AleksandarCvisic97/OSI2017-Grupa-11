#pragma once
#include "User.h"

class Admin : public User
{
	const int code = 0;
public:
	void write();
};

