#pragma once

#include <string>
#include <vector>

typedef std::vector<std::string> stringvec;

class Bill
{
	struct Item
	{
		std::string name; // name = ime
		double amount, price; // amount = kolicina, price = cijena
		Item(const std::string = " ", const double = 0, const double = 0);
	};
	Item *array; // niz artikala sa racuna
	int n; // broj artikala na racunu
	std::string path;
public:
	Bill(const std::string = "");
	~Bill();

	void read_bill();  // TODO: Definisati funkciju koja cita racun iz datoteke
	void write_bill(); // TODO: Definisati funkciju koja pise racun u datoteku
};

void read_directory(const std::string&, stringvec&);