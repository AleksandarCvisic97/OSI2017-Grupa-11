#pragma once

#include <string>

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
public:
	Bill(const int = 0);
	~Bill();

	void read_bill();  // TODO: Definisati funkciju koja cita racun iz datoteke
	void write_bill(); // TODO: Definisati funkciju koja pise racun u datoteku
};

