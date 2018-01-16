#include "Bill.h"
#include <iostream>
#include <windows.h>

Bill::Item::Item(const std::string name, const double amount, const double price) : name(name), amount(amount), price(price) { }

Bill::Bill(const std::string path) : path(path)
{
	array = nullptr;
}

Bill::~Bill()
{
	delete[] array;
	n = 0;
}

void read_directory(const std::string &name, stringvec &v)
{
	std::string pattern(name);
	pattern.append("\\*");
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
		do {
			v.push_back(data.cFileName);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
}
