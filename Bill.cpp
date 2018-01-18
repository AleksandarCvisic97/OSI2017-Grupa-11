#include "Bill.h"
#include <iostream>
#include <windows.h>


Bill::Item::Item(const std::string name, const double amount, const double price) : name(name), amount(amount), price(price) { }

Bill::Bill(const std::string path) : path(path)
{
	array = nullptr;
	file.open(path);
	std::size_t pos = path.find("format");
	if (pos == std::string::npos) // Provjera da li fajl ima u sebi 'format'
		file.close();
	else
	{
		char temp;
		temp = path.at(pos + 6);
		format = atoi(&temp);
	}
}

Bill::~Bill()
{
	delete[] array;
	n = 0;
}

Bill & Bill::operator=(const Bill &other)
{
	this->path = other.path;
	return *this;
}

bool Bill::check_bill()
{
    double sum=0;
    for(int i=0;i<n;i++)
    sum+=array[i].amount*array[i].price;
    if(sum==total)
        return true;
    return false;
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
