#include "User.h"
#include "Admin.h"
#include "Analyst.h"
#include "Menu.h"
#include <iostream>
#include <Windows.h>

User::User(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : name(name), surname(surname), username(username), pin(pin), status(status) {}

void User::write() // Funkcija za upis u datoteku
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::ofstream users;
	users.open("Users.txt", std::ios::app); //prava putanja: ...\programdata\Users.txt
	if (users.is_open())
	{
		users << name << " " << surname << " " << username << " " << pin << " " << status << " ";
		write_code(users);
		users << std::endl;
		users.close();
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		std::cout << "Greska pri otvaranju datoteke: 'Users.txt'";
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}
}

void User::LogIn() // Funkcija za prijavu na sistem
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string LogName, LogPIN;
	std::string name, surname, username, PIN;
	int status, code, p;
	std::fstream users;
	do
	{
		users.open("Users.txt", std::ios::in);
		std::cout << "Unesite Vase korisnicko ime i lozinku!" << std::endl;
		std::cout << "Korisnicko ime:"; std::cin >> LogName;
		std::cout << std::endl << "Lozinka:"; std::cin >> LogPIN;
		const char * A = LogName.c_str();
		const char * B = LogPIN.c_str();
		if (users.is_open())
		{
			while (users >> name >> surname >> username >> PIN >> status >> code)
			{
				const char * C = username.c_str();
				const char * D = PIN.c_str();
				if (std::strcmp(A, C) == 0) // Provjera korisnickog imena
				{
					if (std::strcmp(B, D) == 0) // Provjera lozinke
					{
						if (status == 1) // Provjera da li je nalog aktivan
						{
							std::cout << "Uspjesno ste se prijavili na sistem" << std::endl;
							if (code == 0)
							{
								Admin person(name, surname, username, PIN, 1);
								person.AdminMenuOptions(); // Poziva meni za administratora
							}
							else
							{
								Analyst person(name, surname, username, PIN, 1);
								person.AnalystMenuOptions(); // Poziva meni za analiticara
							}
							return;
						}
						else
						{
							SetConsoleTextAttribute(h, FOREGROUND_RED);
							std::cout << "Vas nalog je deaktiviran! Prijava nije moguca." << std::endl << std::endl;
							SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
							return;
						}
					}
				}
			}
			users.close();
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << "Unijeli ste pogresno korisnicko ime ili pogresnu lozinku!" << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
			do
			{
				std::cout << "Ponovna prijava (1)" << std::endl << "Napusti program (0)" << std::endl << "Vas izbor: ";
				std::cin >> p;
				if (p > 1 || p < 0)
				{
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
					std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				}
			} while (p > 1 || p < 0);
		}
		else
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED);
			std::cout << "Greska pri otvaranju datoteke: 'Users.txt'";
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		}
	} while (p);
}

int User::registername(std::string new_username) // Funkcija za provjeru korisnickog imena
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string username, name, surname, pin;
	int confirmation, status, code;

	std::fstream in;
	in.open("Users.txt", std::ios::in);
	if (in.is_open())
	{


		while (in >> name >> surname >> username >> pin >> status >> code)
		{

			confirmation = new_username.compare(username);

			if (confirmation == 0)
			{
				in.close();
				return confirmation;
			}
		}
		confirmation = 1;
		in.close();
		return confirmation;

	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		std::cout << "Neuspjesno otvaranje datoteke 'Users.txt'!" << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		return 0;
	}
}

void User::PlaceRequest() // Funkcija za smjestanje zahtjeva za registraciju
{   
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string name,surname,username,pin;
	int code,p,k=1;
	while (k)
	{
		std::cout << "Registruj se kao Administrator (unesi 1) ili Analiticar (unesi 2) ?" << std::endl;
		std::cout << "Vas izbor: "; std::cin >> p;
		if (p == 1)
		{
			code = 0;
			k = 0;
		}
		else if (p == 2)
		{
			code = 1;
			k = 0;
		}
		else
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		}
	}
    std::cout<<"Ime:";
    std::cin>>name;
    std::cout<<"Prezime:";
    std::cin>>surname;
	k = 1;
	while (k)
	{
		std::cout << "Korisnicko ime:";
		std::cin >> username;
		if (!registername(username))
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << "Korisnicko ime je zauzeto! Pokusajte ponovo." << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else
			k = 0;
	}
	k = 1;
	while (k)
	{
		std::cout << "PIN (4 cifre!):";
		std::cin >> pin;
		if (pin.length() != 4)
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << "Pin se mora sastojati od 4 cifre! Pokusaj ponovo." << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else
			k = 0;
	}
    int status=0; //nalog je samo smjesten u datoteku,neaktivan
    std::ofstream file;
    file.open ("Requests.txt",std::ios::app);
    if(file.is_open())
    {
		file << name << " " << surname << " " << username << " " << pin << " " << status << " " << code << std::endl;
        file.close();
    }
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		std::cout << "Neuspjesno otvaranje datoteke o korisnicima!" << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}
	std::cout << "Vas zahtjev je poslan administratoru."<<std::endl<<"Nakon izvjesnog vremena pokusajte sa prijavom na sistem koja bi trebala biti uspjesna ukoliko je zahtjev odobren." << std::endl << std::endl;
}

void User::changeStatus() // Funkcija za promjenu statusa naloga
{
	if (status)
		status = 0;
	else
		status = 1;
}

std::ostream & operator<<(std::ostream &stream, const User &u)
{
	stream << u.name << " " << u.surname << " " << u.username << " " << u.status << " ";
	u.print_code(stream);
	stream << std::endl;
	return stream;
}

void User::Deactivate() // Funkcija za deaktivaciju naloga
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	struct temp // Pomocna struktura
	{
		std::string name, surname, username, pass;
		int stat, kod;
		temp(std::string a = "", std::string b = "", std::string c = "", std::string d = "", int e = 0, int f = 0) : name(a), surname(b), username(c), pass(d), stat(e), kod(f) {}
	};
	int n = 0, j = 0, k = 1;
	std::vector<temp> arr; // Pomocni niz
	arr.reserve(50);
	temp user; // Promjenljiva za prihvatanje podataka iz fajla
	std::string korIme, pin;
	std::cout << "Vase korisnicko ime: " << std::endl;
	std::cin >> korIme; // Trazeni nalog za deaktivaciju
	while (k)
	{
		std::cout << "Vasa lozinka:";
		std::cin >> pin;
		if (pin.length() != 4)
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN);
			std::cout << "Pin se mora sastojati od 4 cifre! Pokusaj ponovo." << std::endl;
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else
			k = 0;
	}
	std::fstream users;
	users.open("Users.txt", std::ios::in);
	if (users.is_open())
	{
		while (users >> user.name >> user.surname >> user.username >> user.pass >> user.stat >> user.kod)
		{
			if (((user.username).compare(korIme) == 0) && ((user.username).compare("sca") != 0) && ((user.pass).compare(pin) == 0)) // Ako je pronadjen nalog mijenja se status iz aktivnog u neaktivni
			{
				user.stat = 0;
				j = 1;
			}
			arr.push_back(temp(user.name, user.surname, user.username, user.pass, user.stat, user.kod));
		}
		users.close();
	}
	else
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		std::cout << "Greska pri otvaranju datoteke 'Users.txt'" << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}
	if (j == 0)
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED);
		std::cout << "Deaktiviranje naloga nije uspjelo, pogresno korisnicko ime ili lozinka! " << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else
	{
		users.open("Users.txt", std::ios::out);
		if (users.is_open()) // Upisivasnje nazad u fajl sa deaktiviranim nalogom
		{
			for (j = 0; j < (int)arr.size(); j++)
				users << arr[j].name << " " << arr[j].surname << " " << arr[j].username << " " << arr[j].pass << " " << arr[j].stat << " " << arr[j].kod << std::endl;
			users.close();
		}
		SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		std::cout << "Nalog je uspjesno deaktiviran." << std::endl;
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	}
}