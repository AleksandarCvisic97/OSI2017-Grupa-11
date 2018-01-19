#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

typedef std::vector<std::string> stringvec;

class Bill
{
	struct Item // struktura za artikle sa racuna
	{
		std::string name; // name = ime
		double amount, price; // amount = kolicina, price = cijena
		Item(const std::string = "", const double = 0, const double = 0);
	};
	struct Date // struktura za datum
	{
		int dd, mm, yy;
		Date(int dd = 1, int mm = 1, int yy = 2000) : dd(dd), mm(mm), yy(yy) {}
	};

	Item *array; // niz artikala sa racuna
	int n; // broj artikala na racunu
	int format; // format racuna (1-5)
	std::string path; // lokacija racuna
	std::ifstream file; // fajl racuna
	double total; // ukupna cijena racuna
	std::string buyer; // ime kupca
	Date billDate; // datum racuna
public:
	Bill(const std::string = "");
	~Bill();
	Bill& operator=(const Bill&);
	void read_bill();  // TODO: Definisati funkciju koja cita racun iz datoteke
	void write_bill(); // TODO: Definisati funkciju koja pise racun u datoteku


};

	bool check_bill(std::ifstream& ,int ); //Funkcija za provjeru da li je suma ukupnih cijena za sve proizvode jednaka ukupnoj vrijednosti racuna
void read_directory(const std::string&, stringvec&);
int check_format(std::ifstream& ); // Provjerava da li format racuna odgovara nekom od 5 zadanih
void read_bill(std::ifstream& , int );
std::string removeSpaces(std::string);
