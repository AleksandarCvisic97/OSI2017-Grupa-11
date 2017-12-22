#include "User.h"
#include <iostream>

User::User(const std::string name, const std::string surname, const std::string username, const std::string pin, const int status) : name(name), surname(surname), username(username), pin(pin), status(status) {}

void User::write()
{
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
		std::cout << "Greska pri otvaranju datoteke: 'Users.txt'";
}

void User::LogIn()
{
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
				if (std::strcmp(A, C) == 0)
				{
					if (std::strcmp(B, D) == 0)
					{
						std::cout << "Uspjesno ste se prijavili na sistem" << std::endl;
						//pozivanje "admin menu" funkcije ako se prijavio admin ili "analyst menu" ako je analiticar
						return;
					}
				}
			}
			users.close();
			std::cout << "Unijeli ste pogresno korisnicko ime ili pogresnu lozinku!" << std::endl;
			do
			{
				std::cout << "Ponovna prijava (1)" << std::endl << "Napusti program (0)" << std::endl << "Vas izbor: ";
				std::cin >> p;
				if (p > 1 || p < 0)
					std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
			} while (p > 1 || p < 0);
		}
		else
			std::cout << "Greska pri otvaranju datoteke: 'Users.txt'";
	} while (p);
}

void User::PlaceRequest()
{   std::string name,surname,username,pin;
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
			std::cout << "Nepostojeca opcija! Pokusajte ponovo." << std::endl;
	}
    std::cout<<"Ime:";
    std::cin>>name;
    std::cout<<"Prezime:";
    std::cin>>surname;
    std::cout<<"Korisnicko ime:";
    std::cin>>username;
	k = 1;
	while (k)
	{
		std::cout << "PIN (4 cifre!):";
		std::cin >> pin;
		if (pin.length() != 4)
			std::cout << "Pin se mora sastojati od 4 cifre! Pokusaj ponovo." << std::endl;
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
	else std::cout << "Neuspjesno otvaranje datoteke o korisnicima!" << std::endl;
	std::cout << "Vas zahtjev je poslan administratoru."<<std::endl<<"Nakon izvjesnog vremena pokusajte sa prijavom na sistem koja bi trebala biti uspijesna ukoliko je zahtjev odobren." << std::endl;
}

int User::registername(std::string new_username)
{

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
		std::cout << "Neuspjesno otvaranje datoteke 'Users.txt'!" << std::endl;
	return 0;
    }
}

void User::changeStatus()
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
