#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

typedef std::vector<std::string> stringvec;

bool check_bill(std::ifstream& ,int ); //Funkcija za provjeru da li je suma ukupnih cijena za sve proizvode jednaka ukupnoj vrijednosti racuna
void read_directory(const std::string&, stringvec&); //funkcija za citanje direktorijuma
int check_format(std::ifstream& ); // Provjerava da li format racuna odgovara nekom od 5 zadanih
void read_bill(std::ifstream& , int);
std::string removeSpaces(std::string);
