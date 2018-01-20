#include "Bill.h"
#include <iostream>
#define NOMINMAX
#include <windows.h>

bool check_bill(std::ifstream& file, int format)
{
    std::string line,temp,pom;
    int counter=0;
    double price,amount,total,total_product,total_with_pdv,pdv,sum=0; // Total-ukupna cijena ocitana sa racuna,sum-ukupna cijena koja se dobija na osnovu ocitanih podataka
    if(format==1)
    {
        for(int i=0; i<6; i++)
            std::getline(file,line);
        while(std::getline(file,line))
            counter++;
        file.clear();
        file.seekg( std::ios::beg);
        for(int i=0; i<6; i++)
            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Preskace liniju u datoteci
        for(int i=0; i<counter-4; i++)
        {
            std::getline(file,line);
            std::stringstream s(line);
            std::getline(s,temp,'-');
            std::getline(s,temp,'-');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end()); // Brise sve razmake iz stringa temp
            amount=atof(temp.c_str());
            std::getline(s,temp,'-');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            price=atof(temp.c_str());
            std::getline(s,temp,'\n');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            total_product=atof(temp.c_str());
            if(total_product!=amount*price) // Provjera da li je ukupna cijena za taj proizvod tacna
                return false;
            sum+=total_product;

        }
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(file,line);
        std::stringstream ss(line);
        std::getline(ss,temp,':');
        std::getline(ss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total=atof(temp.c_str());
        if(sum!=total) // Provjerava da li je ukupna cijena svih proizvoda jednaka ukupnoj cijeni sa racuna
            return false;
        std::getline(file,line);
        std::stringstream sss(line);
        std::getline(sss,temp,':');
        std::getline(sss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        pdv=atof(temp.c_str());
        std::getline(file,line);
        std::stringstream ssss(line);
        std::getline(ssss,temp,':');
        std::getline(ssss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total_with_pdv=atof(temp.c_str());
        if((total+pdv)!=total_with_pdv) // Provjerava da li je ukupna cijena sa pdv-om tacna
            return false;
        else return true;



    }
    else if(format==2)
    {
        for(int i=0; i<9; i++)
            std::getline(file,line);
        while(std::getline(file,line))
            counter++;
        file.clear();
        file.seekg( std::ios::beg);
        for(int i=0; i<9; i++)
            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        for(int i=0; i<counter-6; i++)
        {
            std::getline(file,line);
            std::stringstream s(line);
            std::getline(s,temp,'-');
            std::getline(s,temp,'-');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            amount=atof(temp.c_str());
            std::getline(s,temp,'-');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            price=atof(temp.c_str());
            std::getline(s,temp,'\n');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            total_product=atof(temp.c_str());
            if(total_product!=amount*price)
                return false;
            sum+=total_product;


        }
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(file,line);
        std::stringstream ss(line);
        std::getline(ss,temp,':');
        std::getline(ss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total=atof(temp.c_str());
        if(sum!=total)
            return false;
        std::getline(file,line);
        std::stringstream sss(line);
        std::getline(sss,temp,':');
        std::getline(sss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        pdv=atof(temp.c_str());
        std::getline(file,line);
        std::stringstream ssss(line);
        std::getline(ssss,temp,':');
        std::getline(ssss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total_with_pdv=atof(temp.c_str());
        if((total+pdv)!=total_with_pdv)
            return false;
        else return true;

    }
    else   if(format==3)
    {
        for(int i=0; i<9; i++)
            std::getline(file,line);

        while(std::getline(file,line))
            counter++;
        file.clear();
        file.seekg( std::ios::beg);
        for(int i=0; i<9; i++)
            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        for(int i=0; i<counter-5; i++)
        {
            std::getline(file,line);
            std::stringstream s(line);
            std::getline(s,temp,'=');
            for(int i=0; i<6; i++)
                std::getline(s,temp,'=');
            amount=atof(temp.c_str());
            for(int i=0; i<6; i++)
                std::getline(s,temp,'=');
            price=atof(temp.c_str());
            for(int i=0; i<5; i++)
                std::getline(s,temp,'=');
            std::getline(s,temp,'\n');
            total_product=atof(temp.c_str());
            if(total_product!=amount*price)
                return false;
            sum+=total_product;

        }
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(file,line);
        std::stringstream ss(line);
        std::getline(ss,temp,':');
        std::getline(ss,temp,'P');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total=atof(temp.c_str());
        if(sum!=total)
            return false;
        std::getline(ss,temp,':');
        std::getline(ss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        pdv=atof(temp.c_str());
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(file,line);
        std::stringstream sss(line);
        std::getline(sss,temp,':');
        std::getline(sss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total_with_pdv=atof(temp.c_str());
        if((total+pdv)!=total_with_pdv)
            return false;
        else return true;

    }

    else if(format==4)
    {
        for(int i=0; i<7; i++)
            std::getline(file,line);
        while(std::getline(file,line))
            counter++;
        file.clear();
        file.seekg( std::ios::beg);
        for(int i=0; i<7; i++)
            file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        for(int i=0; i<counter-7; i++)

        {
            std::getline(file,line);
            std::stringstream s(line);
            std::getline(s,temp,'-');
            std::getline(s,temp,'-');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            amount=atof(temp.c_str());
            std::getline(s,temp,'-');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            price=atof(temp.c_str());
            std::getline(s,temp,'\n');
            temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
            total_product=atof(temp.c_str());
            if(total_product!=amount*price)
                return false;
            sum+=total_product;

        }

        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(file,line);
        std::stringstream ss(line);
        std::getline(ss,temp,':');
        std::getline(ss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total=atof(temp.c_str());
        if(sum!=total)
            return false;
        std::getline(file,line);
        std::stringstream sss(line);
        std::getline(sss,temp,':');
        std::getline(sss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        pdv=atof(temp.c_str());
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(file,line);
        std::stringstream ssss(line);
        std::getline(ssss,temp,':');
        std::getline(ssss,temp,'\n');
        temp.erase(remove_if(temp.begin(), temp.end(), isspace), temp.end());
        total_with_pdv=atof(temp.c_str());
        if((total+pdv)!=total_with_pdv)
            return false;
        else return true;


    }
    else if(format==5)
    {
        while(std::getline(file,line))
            counter++;
        file.clear();
        file.seekg( std::ios::beg);
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        for(int i=0; i<counter-1; i++)
        {
            std::getline(file,line);
            std::stringstream s(line);
            std::getline(s,temp,',');
            std::getline(s,temp,','); // Prelazi se do brojcanih podataka
            amount=atof(temp.c_str());
            std::getline(s,temp,',');
            price=atof(temp.c_str());
            std::getline(s,temp,'\n');
            total_product=atof(temp.c_str());
            if(total_product!=amount*price)
                return false;

        }
    }
    return true;

}



void read_directory(const std::string &name, stringvec &v)
{
    std::string pattern(name);
    pattern.append("\\*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE)
    {
        do
        {
            v.push_back(data.cFileName);
        }
        while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
}
int check_format(std::ifstream& file)
{
    std::string line,temp;
    std::getline(file,line);
    std::stringstream s(line);
    std::getline(s,temp,' ');
    if(temp.compare("Kupac:")==0) // Poredjenje sadrzaja stringa temp i teksta u zagradi
    {
        for(int i=0; i<3; i++)
            std::getline(file,line); // Ucitava liniju iz fajla
        std::stringstream s(line);
        if(line.compare("	       Racun")==0)
            return 1;
        else if(line.compare("	      OSI Market")==0)
            return 4;
        else return 0;

    }
    else if(temp.compare("OSI")==0)
    {
        for(int i=0; i<3; i++)
            std::getline(file,line);
        std::stringstream s(line);
        std::getline(s,temp,' ');
        temp.erase(std::remove(temp.begin(),temp.end(),' '),temp.end());
        if(temp.compare("Datum:")==0)
            return 3;
        else if(temp.compare("	Maloprodajni")==0)
            return 2;
        else return 0;

    }
    else
    {
        file.seekg( std::ios::beg);
        std::getline(file,line);
        std::stringstream s(line);
        if(line.compare("Sifra,Kolicina,Cijena,Ukupno")==0)
            return 5;
    }

    return 0;

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
                for(int i=0; i<4; i++)
                    std::getline(bill,line);
            }
            else if(format==4)
            {
                for(int i=0; i<5; i++)
                    std::getline(bill,line);
            }

//provjerava preostali broj linija
            while(std::getline(bill,line))
                lineNumber++;

            bill.clear();
            bill.seekg( std::ios::beg);

            if(format==1)
                for(int i=0; i < 6; ++i)
                {
                    bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
            else
                for(int i=0; i < 7; ++i)
                {
                    bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }


//provjerava broj proizvoda
            if(format==1)
                productNumber=lineNumber-4;
            else
                productNumber=lineNumber-7;

//uzima podatke za svaki proizvod
            for(int i=0; i<productNumber; i++)
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

            for(int i=0; i<5; i++)
                std::getline(bill,line);


            std::getline(bill,line);
            std::stringstream ss(line);
            std::getline(ss,data,':');
            std::getline(ss,customerPom,'\n');
            customer=removeSpaces(customerPom);     //kupac

            for(int i=0; i<3; i++)
                std::getline(bill,line);

//provjerava preostali broj linija
            while(std::getline(bill,line))
                lineNumber++;


            bill.clear();
            bill.seekg( std::ios::beg);

//prelazi do linije datuma

            for(int i=0; i < lineNumber+8; ++i)
            {
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
            for(int i=0; i < 9; ++i)
            {
                bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }


//uzima podatke za svaki proizvod
            for(int i=0; i<productNumber; i++)
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


            for(int i=0; i<3; i++)
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


            for(int i=0; i<5; i++)
                std::getline(bill,line);

//provjerava preostali broj linija
            while(std::getline(bill,line))
                lineNumber++;

            bill.clear();
            bill.seekg( std::ios::beg);

            for(int i=0; i < 9; ++i)
            {
                bill.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }

//provjerava broj proizvoda
            productNumber=lineNumber-5;
            std::string help;
//uzima podatke za svaki proizvod
            for(int i=0; i<productNumber; i++)
            {

                std::getline(bill,line);
                std::stringstream ss(line);
                std::getline(ss,name,'=');            //naziv

                for(int i=0; i<5; i++)
                {
                    std::getline(ss,amountPom,'=');
                }
                std::getline(ss,amount,'=');          //kolicina

                for(int i=0; i<5; i++)
                {
                    std::getline(ss,pricePom,'=');
                }
                std::getline(ss,price,'=');             //cijena

                for(int i=0; i<5; i++)
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

            for(int i=0; i<lineNumber-1; i++)
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



