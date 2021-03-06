#include "Analyst.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <Windows.h>

void Analyst::write_code(std::ofstream &stream) const
{
	stream << code;
}

void Analyst::print_code(std::ostream &stream) const
{
	stream << code;
}

void move_bill(std::string oldpath, std::string newpath)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (MoveFile(oldpath.c_str(), newpath.c_str()))
		return;
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		std::cout << "GRESKA.";
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}
}
void Analyst::read_bills()
{
	stringvec str;
	read_directory("Bills.", str);
	std::ifstream file;

	for (std::string temp : str)
	{

		if (temp.find(".txt") != std::string::npos || temp.find(".csv") != std::string::npos) // Provjera da li je .txt ili .csv
		{

			std::string localTemp = ".\\Bills\\"; // Dodavanje relativne putanje
			localTemp.append(temp);
			file.open(localTemp);
			if (file.is_open())
			{
				int format = check_format(file);
				file.seekg(0, std::ios::beg);
				if (check_bill(file, format) == true) // Ako je racun validan
				{
					file.seekg(0, std::ios::beg);
					read_bill(file, format);
					file.close();
					std::string newPath = ".\\Valide\\"; // Dodavanje relativne putanje
					newPath.append(temp);
					move_bill(localTemp, newPath);
				}
				else								  // Ako racun nije validan
				{
					file.close();
					std::string newPath = ".\\Error\\"; // Dodavanje relativne putanje
					newPath.append(temp);
					move_bill(localTemp, newPath);
				}
			}
		}

	}
}
Analyst::Analyst(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : User(name, surname, username, pin, status) {}

int Analyst::get_code() const
{
	return code;
}

void Month_print(int k)
{
	switch (k)
	{
	case 1: std::cout << "Januar"; break;
	case 2: std::cout << "Februar"; break;
	case 3: std::cout << "Mart"; break;
	case 4: std::cout << "April"; break;
	case 5: std::cout << "Maj"; break;
	case 6: std::cout << "Jun"; break;
	case 7: std::cout << "Jul"; break;
	case 8: std::cout << "Avgust"; break;
	case 9: std::cout << "Septembar"; break;
	case 10: std::cout << "Oktobar"; break;
	case 11: std::cout << "Novembar"; break;
	case 12: std::cout << "Decembar"; break;
	default:
		break;
	}
}

void ShowData(int n) // Funkcija za prikaz podataka
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string name_temp, amount_temp, price_temp, total_temp, customer_temp, date_temp; // Pomocne promjenljive za prihvatanje podataka o proizvodu
	struct Product //Pomocna struktura za formiranje proizvoda
	{
		std::string name_str, amount_str, price_str, total_str, customer_str, date_str;
		double d_amount, d_price, d_total;
		int day, month, year;
		Product(std::string a,std::string b,std::string c,std::string d,std::string e,std::string f) : name_str(a),amount_str(b),price_str(c),total_str(d),customer_str(e),date_str(f) {}
	};
	struct Final_Product // Konacna forma proizvoda
	{
		std::string name, customer; // Naziv proizvoda i kupca, respektivno
		double amount, price, total; // Kolicina, cijena, ukupno
		int dd, mm, yy; // Varijable za predstavljanje datuma
		Final_Product(std::string a,std::string b,double c,double d,double e,int f,int g, int h) : name(a),customer(b),amount(c),price(d),total(e),dd(f),mm(g),yy(h) {}
	};
	std::fstream database;
	int i,p=0;
	float PDV = 1.17;
	std::vector<Product> AllInOne; // Prvobitni niz
	AllInOne.reserve(300);
	database.open("Storage.txt", std::ios::in);
	if (database.is_open())
	{
		while (database >> amount_temp >> price_temp >> total_temp >> customer_temp >> date_temp >> name_temp) 
		{
			AllInOne.push_back(Product(name_temp, amount_temp, price_temp, total_temp, customer_temp, date_temp)); // Citanje proizvoda iz datoteke
			p++;
		}
		for (i = 0; i < (int)AllInOne.size(); ++i) // Konvertovanje polja
		{
			AllInOne[i].d_amount = std::atof(AllInOne[i].amount_str.c_str());
			AllInOne[i].d_price = std::atof(AllInOne[i].price_str.c_str());
			AllInOne[i].d_total = std::atof(AllInOne[i].total_str.c_str());
			sscanf_s(AllInOne[i].date_str.c_str(), "%d/%d/%d", &AllInOne[i].day, &AllInOne[i].month, &AllInOne[i].year);
		}
		if (n == 1) // Sortira za odredjenog kupca
		{
			std::string wanted;
			std::cout << "Unesite tacan naziv kupca:";
			std::cin >> wanted;
			std::vector<Final_Product> arr;
			arr.reserve(300);
			for (i = 0; i < (int)AllInOne.size(); ++i) // Filtrira niz po zadanom kupcu
			{
				if ((wanted).compare(AllInOne[i].customer_str) == 0)
					arr.push_back(Final_Product(AllInOne[i].name_str, AllInOne[i].customer_str, AllInOne[i].d_amount, AllInOne[i].d_price, AllInOne[i].d_total, AllInOne[i].day, AllInOne[i].month, AllInOne[i].year));
			}
			if (((int)arr.size()) == 0)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
				std::cout << "Trazeni kupac ne postoji u bazi podataka. Provjerite tacan naziv kupca." << std::endl;
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				return;
			}
			std::vector<Final_Product> to_print; // Konacni niz
			to_print.reserve(300);
			to_print.push_back(Final_Product(arr[0].name, arr[0].customer, arr[0].amount, arr[0].price, arr[0].total, arr[0].dd, arr[0].mm, arr[0].yy));
			int k, j, p,sum=0;
			for (k = 1; k < (int)arr.size(); ++k) // Formiranje konacnog niza
			{
				p = 0;
				for (j = 0; j < (int)to_print.size(); ++j)
				{
					if ((arr[k].name).compare(to_print[j].name) == 0)  // Filtriranje duplih proizvoda
					{
						p = 1;
						to_print[j].amount += arr[k].amount;
						to_print[j].total += arr[k].total;
					}
				}
				if (p == 0)
					to_print.push_back(Final_Product(arr[k].name, arr[k].customer, arr[k].amount, arr[k].price, arr[k].total, arr[k].dd, arr[k].mm, arr[k].yy));
			}
			std::cout << std::endl;
			std::cout << "================================================" << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			std::cout << "       Prikaz podataka za kupca: " << wanted << std::endl << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << std::setw(15) << std::left << "Naziv" << std::setw(12) << "Kolicina" << std::setw(12) << "Cijena" << std::setw(12) << "Ukupno" << std::setw(12) << std::endl;
			std::cout << "================================================" << std::endl;
			for (i = 0; i < (int)to_print.size(); ++i) 
			{
				sum += to_print[i].total;
				std::cout << std::setw(15) << std::left << to_print[i].name << std::setw(12) << to_print[i].amount << std::setw(12) << to_print[i].price << std::setw(12) << to_print[i].total << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Kupac " << wanted << " je ukupno potrosio sljedeci iznos: " << (sum*PDV) << std::endl << std::endl;
		}
		if (n == 2) // Sortiranje za odredjeni mjesec
		{
			int wanted;
			std::cout << "Unesite redni broj mjeseca u godini:";
			std::cin >> wanted;
			std::vector<Final_Product> arr;
			arr.reserve(50);
			for (i = 0; i < (int)AllInOne.size(); ++i) // Filtriranje za zadani mjesec
			{
				if (AllInOne[i].month == wanted)
					arr.push_back(Final_Product(AllInOne[i].name_str, AllInOne[i].customer_str, AllInOne[i].d_amount, AllInOne[i].d_price, AllInOne[i].d_total, AllInOne[i].day, AllInOne[i].month, AllInOne[i].year));
			}
			if (((int)arr.size()) == 0)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
				std::cout << "U trazenom mjesecu nije bilo prometa ili ste napravili nepravilan unos."<<std::endl;
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				return;
			}
			std::vector<Final_Product> to_print; // Konacni niz
			to_print.reserve(50);
			to_print.push_back(Final_Product(arr[0].name, arr[0].customer, arr[0].amount, arr[0].price, arr[0].total, arr[0].dd, arr[0].mm, arr[0].yy));
			int k, j, p, sum = 0;
			for (k = 1; k < (int)arr.size(); ++k) // Formiranje konacnog niza
			{
				p = 0;
				for (j = 0; j < (int)to_print.size(); ++j)
				{
					if ((arr[k].name).compare(to_print[j].name) == 0) // Filtriranje duplih proizvoda
					{
						p = 1;
						to_print[j].amount += arr[k].amount;
						to_print[j].total += arr[k].total;
					}
				}
				if (p == 0)
					to_print.push_back(Final_Product(arr[k].name, arr[k].customer, arr[k].amount, arr[k].price, arr[k].total, arr[k].dd, arr[k].mm, arr[k].yy));
			}
			std::cout << std::endl;
			std::cout << "==========================================================" << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			std::cout << "       Prikaz podataka za mjesec: "; Month_print(wanted); std::cout << std::endl << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << std::setw(15) << std::left << "Naziv" << std::setw(12) << "Kolicina" << std::setw(12) << "Cijena" << std::setw(12) << "Ukupno" << std::setw(12) << "Kupac" << std::endl;
			std::cout << "==========================================================" << std::endl;
			for (i = 0; i < (int)to_print.size(); ++i) // Ispis i sumiranje troskova
			{
				sum += to_print[i].total;
				std::cout << std::setw(15) << std::left << to_print[i].name << std::setw(12) << to_print[i].amount << std::setw(12) << to_print[i].price << std::setw(12) << to_print[i].total <<std::setw(12)<<to_print[i].customer<<std::endl;
			}
			std::cout << std::endl;
			std::cout << "U " << wanted << ". mjesecu je ukupno potrosen sljedeci iznos: " << (sum*PDV) << std::endl << std::endl;
		}
		if (n == 3) // Sortiranje za odredjeni proizvod
		{
			std::string wanted;
			std::cout << "Unesite tacan naziv proizvoda (Napomena: Razmaci u nazivu trebaju biti popunjeni sa '_' !): ";
			std::cin >> wanted;
			std::vector<Final_Product> arr;
			arr.reserve(50);
			for (i = 0; i < (int)AllInOne.size(); ++i)  // Filtriranje za zadani proizvod
			{
				if ((wanted).compare(AllInOne[i].name_str) == 0)
					arr.push_back(Final_Product(AllInOne[i].name_str, AllInOne[i].customer_str, AllInOne[i].d_amount, AllInOne[i].d_price, AllInOne[i].d_total, AllInOne[i].day, AllInOne[i].month, AllInOne[i].year));
			}
			if (((int)arr.size()) == 0)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
				std::cout << "Trazeni proizvod ne postoji u bazi podataka. Provjerite da li ste unijeli tacan naziv." << std::endl;
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				return;
			}
			std::vector<Final_Product> to_print; // Konacni niz
			to_print.reserve(300);
			to_print.push_back(Final_Product(arr[0].name, arr[0].customer, arr[0].amount, arr[0].price, arr[0].total, arr[0].dd, arr[0].mm, arr[0].yy));
			int k, j, p, sum = 0;
			for (k = 1; k < (int)arr.size(); ++k) // Formiranje konacnog niza
			{
				p = 0;
				for (j = 0; j < (int)to_print.size(); ++j)
				{
					if ((arr[k].customer).compare(to_print[j].customer) == 0) // Filtriranje duplih proizvoda
					{
						p = 1;
						to_print[j].amount += arr[k].amount;
						to_print[j].total += arr[k].total;
					}
				}
				if (p == 0)
					to_print.push_back(Final_Product(arr[k].name, arr[k].customer, arr[k].amount, arr[k].price, arr[k].total, arr[k].dd, arr[k].mm, arr[k].yy));
			}
			std::cout << std::endl;
			std::cout << "================================================" << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			std::cout << "       Prikaz podataka za proizvod: " << wanted << std::endl << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << std::setw(15) << std::left << "Kupac" << std::setw(12) << "Kolicina" << std::setw(12) << "Cijena" << std::setw(12) << "Ukupno" << std::endl;
			std::cout << "================================================" << std::endl;
			for (i = 0; i < (int)to_print.size(); ++i) // Ispis i sumiranje
			{
				sum += to_print[i].total;
				std::cout << std::setw(15) << std::left << to_print[i].customer << std::setw(12)  << to_print[i].amount << std::setw(12)  << to_print[i].price << std::setw(12) << to_print[i].total << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Na proizvod " << wanted << " je ukupno potrosen sljedeci iznos: " << (sum*PDV) << std::endl << std::endl;
		}
	}
}

int Analyst::AnalystMenuOptions() // Meni za analititcara
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	read_bills();
	char c;
	do
	{
		print_analyst_menu();
		std::cin >> c;
		switch (c)
		{
		case '1': ShowData(1); break; // Poziva prikaz podataka za odredjenog kupca
		case '2': ShowData(2); break; // Poziva prikaz podataka za odredjeni mjesec
		case '3': ShowData(3); break; // Poziva prikaz podataka za odredjeni proizvod
		case '4': std::cout << "Dovidjenja!" << std::endl; return 0; break;
		default: SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
				 std::cout << "Nepostojeca opcija! Pokusajte ponovo" << std::endl;
				 SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); break;
		}
	} while (true);
}