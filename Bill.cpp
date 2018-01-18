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


void read_bill(std::ifstream& bill, int format)
{


    int lineNumber=0,productNumber=0;
    std::string customer,name,line,data,amount,price,total,date,datePom,amountPom,pricePom,totalPom,customerPom;


    std::ofstream storage;
    storage.open("Storage.txt",std::ofstream::app);

    if (storage.is_open())
	{


	    if(format==1 || format==4)
        {
            std::getline(bill,line);
            std::stringstream ss(line);
            std::getline(ss,data,':');
            std::getline(ss,customerPom,'\n');
            customer=removeSpaces(customerPom);      //kupac
            std::getline(bill,line);
            std::stringstream s(line);
            std::getline(s,data,':');
            std::getline(s,datePom,'\n');
            date=removeSpaces(datePom);     //datum

//prelazak do linija sa proizvodima
       if(format==1)
       {
             for(int i=0;i<4;i++)
                std::getline(bill,line);
       }
        else if(format==4)
        {
             for(int i=0;i<5;i++)
                std::getline(bill,line);
        }

 //provjerava preostali broj linija
         while(std::getline(bill,line))
         lineNumber++;

         bill.clear();
bill.seekg( std::ios::beg);

if(format==1)
for(int i=0; i < 6; ++i){
        bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    else
for(int i=0; i < 7; ++i){
        bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }


//provjerava broj proizvoda
if(format==1)
productNumber=lineNumber-4;
else
productNumber=lineNumber-7;

//uzima podatke za svaki proizvod
for(int i=0;i<productNumber;i++)
        {
            std::getline(bill,line);
            std::stringstream ss(line);

            std::getline(ss,name,'-');            //naziv
            std::getline(ss,amountPom,'-');          //kolicina
            amount=removeSpaces(amountPom);
            std::getline(ss,pricePom,'-');             //cijena
            price=removeSpaces(pricePom);
            std::getline(ss,totalPom,'\n');        //ukupno
            total=removeSpaces(totalPom);


            storage<<amount<<" "<<price<<" "<<total<<" "<<customer<<" "<<date<<" "<<name;
            storage<<std::endl;

        }

        }
        else if(format==2)
        {

            for(int i=0;i<5;i++)
                std::getline(bill,line);


       std::getline(bill,line);
            std::stringstream ss(line);
            std::getline(ss,data,':');
            std::getline(ss,customerPom,'\n');
            customer=removeSpaces(customerPom);     //kupac

            for(int i=0;i<3;i++)
                std::getline(bill,line);

 //provjerava preostali broj linija
         while(std::getline(bill,line))
         lineNumber++;


         bill.clear();
bill.seekg( std::ios::beg);

//prelazi do linije datuma

for(int i=0; i < lineNumber+8; ++i){
        bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

    std::getline(bill,line);
            std::stringstream s(line);
            std::getline(s,data,':');
            std::getline(s,datePom,'\n');
            date=removeSpaces(datePom);       //datum


//provjerava broj proizvoda
productNumber=lineNumber-6;

//prelazi do linije proizvoda
         bill.clear();
bill.seekg(0, std::ios::beg);
for(int i=0; i < 9; ++i){
        bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }


//uzima podatke za svaki proizvod
for(int i=0;i<productNumber;i++)
        {
            std::getline(bill,line);
            std::stringstream ss(line);

            std::getline(ss,name,'-');            //naziv
            std::getline(ss,amountPom,'-');          //kolicina
            amount=removeSpaces(amountPom);
            std::getline(ss,pricePom,'-');             //cijena
            price=removeSpaces(pricePom);
            std::getline(ss,totalPom,'\n');        //ukupno
            total=removeSpaces(totalPom);


            storage<<amount<<" "<<price<<" "<<total<<" "<<customer<<" "<<date<<" "<<name;
            storage<<std::endl;

        }
        }


          else if(format==3)
        {


            for(int i=0;i<3;i++)
             std::getline(bill,line);
            std::stringstream ss(line);
            std::getline(ss,data,':');
            std::getline(ss,customerPom,'\n');
            customer=removeSpaces(customerPom);      //kupac

            std::getline(bill,line);
            std::stringstream s(line);
            std::getline(s,data,':');
            std::getline(s,datePom,'\n');
            date=removeSpaces(datePom);     //datum


            for(int i=0;i<5;i++)
                std::getline(bill,line);

//provjerava preostali broj linija
         while(std::getline(bill,line))
         lineNumber++;

         bill.clear();
bill.seekg( std::ios::beg);

for(int i=0; i < 9; ++i){
        bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

//provjerava broj proizvoda
productNumber=lineNumber-5;
std::string help;
//uzima podatke za svaki proizvod
for(int i=0;i<productNumber;i++)
        {

            std::getline(bill,line);
           std::stringstream ss(line);
            std::getline(ss,name,'=');            //naziv

            for(int i=0;i<5;i++)
            {
                std::getline(ss,amountPom,'=');
            }
            std::getline(ss,amount,'=');          //kolicina

           for(int i=0;i<5;i++)
            {
                std::getline(ss,pricePom,'=');
            }
            std::getline(ss,price,'=');             //cijena

           for(int i=0;i<5;i++)
            {
                std::getline(ss,totalPom,'=');
            }
            std::getline(ss,total,'\n');        //ukupno



            storage<<amount<<" "<<price<<" "<<total<<" "<<customer<<" "<<date<<" "<<name;
            storage<<std::endl;

        }


        }

        else if(format==5)
        {
            customer="Nepoznato";
            date="Nepoznato";

            //provjerava broj linija
         while(std::getline(bill,line))
         lineNumber++;

         bill.clear();
bill.seekg( std::ios::beg);

std::getline(bill,line);

            for(int i=0;i<lineNumber-1;i++)
        {
            std::getline(bill,line);
            std::stringstream ss(line);

            std::getline(ss,name,',');            //naziv
            std::getline(ss,amount,',');          //kolicina
            std::getline(ss,price,',');             //cijena
            std::getline(ss,total,'\n');        //ukupno


            storage<<amount<<" "<<price<<" "<<total<<" "<<customer<<" "<<date<<" "<<name;
            storage<<std::endl;

        }



        }

else
    std::cout<<"Pogresan format"<<std::endl;



	}
	else
        std::cout << "Greska pri otvaranju datoteke: 'Storage.txt'";


 storage.close();
 return;

}


std::string removeSpaces(std::string input)
{
  input.erase(std::remove(input.begin(),input.end(),' '),input.end());
  return input;
}



