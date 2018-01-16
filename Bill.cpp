#include "Bill.h"


Bill::Item::Item(const std::string name, const double amount, const double price) : name(name), amount(amount), price(price) { }

Bill::Bill(const int n) : n(n)
{
	array = new Item[n];
}

Bill::~Bill()
{
	delete[] array;
	n = 0;
}
