/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 December 2022
time - 1:54pm
*/
#include "Motorcycle.h"
using namespace std;
namespace sdds
{
    Motorcycle::Motorcycle()
    {
        sidecar = false;
    }
    Motorcycle::Motorcycle(const char *licensePlate, const char *makeModel) : Vehicle(licensePlate, makeModel)
    {
        sidecar = false;
    }
    Motorcycle::~Motorcycle()
    {
    }
    Motorcycle::Motorcycle(const Motorcycle &src) : Vehicle(src)
    {
        sidecar = src.sidecar;
    }
    Motorcycle &Motorcycle::operator=(const Motorcycle &src)
    {
        if (this != &src)
        {
            Vehicle::operator=(src);
            sidecar = src.sidecar;
        }
        return *this;
    }
    istream &Motorcycle::read(istream &istr)
    {
        if (isCsv())
        {
            Vehicle::read(istr);
            istr >> sidecar;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout << endl
                 << "Motorcycle information entry" << endl;
            Vehicle::read(istr);
            cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            string answer;
            getline(istr, answer);
            while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                getline(istr, answer);
            }
            if(answer == "Y" || answer == "y")
                sidecar = true;
            else
                sidecar = false;
        }
        return istr;
    }

    ostream &Motorcycle::write(ostream &ostr) const
    {
        if (isEmpty())
        {
            ostr << "Invalid Motorcycle Object" << endl;
        }
        else
        {
            
            Vehicle::write(ostr);
            if (isCsv())
            {
                ostr << sidecar << endl;
            }
            else
            {
                if (sidecar)
                {    
                    ostr << "With Sidecar" << endl;
                }
            }
        }
        return ostr;
    }

    ostream &Motorcycle::writeType(ostream &ostr) const
    {

        if (isCsv())
        {
            ostr << "M,";
        }
        else
        {
            ostr << "Vehicle type: Motorcycle" << endl;
        }
        return ostr;
    }
}
