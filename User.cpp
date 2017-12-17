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
	int status, code;
	std::fstream users;
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
					std::cout << "Uspjesno ste se prijavili na sistem";
					//pozivanje "admin menu" funkcije ako se prijavio admin ili "analyst menu" ako je analiticar
				}
				else
				{
					std::cout << "Unesena lozinka nije validna" << std::endl << "Molim pokusajte ponovo" << std::endl;
					users.close();
					return;
				}
			}
			else
			{
				std::cout << "Uneseno korisnicko ime nije validno" << std::endl << "Molim pokusajte ponovo" << std::endl;
				users.close();
				return;
			}
		}
		users.close();
	}
	else
		std::cout << "Greska pri otvaranju datoteke: 'Users.txt'";
}

void User::PlaceRequest()
{   std::string name,surname,username,pin;
    std::cout<<"Name:";
    std::cin>>name;
    std::cout<<"Surname:";
    std::cin>>surname;
    std::cout<<"Username:";
    std::cin>>username;
    std::cout<<"PIN (4 cifre!):";
    std::cin>>pin;
    int status=0; //nalog je samo smjesten u datoteku,neaktivan
    std::ofstream file;
    file.open ("Requests.txt",std::ios::app);
    if(file.is_open())
    {
        file <<name<<" "<<surname<<" "<<username<<" "<<pin<<" "<<status<<" ";
        write_code(file);
        file<<std::endl;
        file.close();
    }
    else std::cout<<"Neuspjesno otvaranje datoteke o korisnicima!";
}
