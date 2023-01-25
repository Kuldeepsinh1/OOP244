/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 December 2022
time - 1:54pm
*/
#include "Car.h"
using namespace std;
namespace sdds
{
    Car::Car()
    {
        carwash = false;
    }
    Car::Car(const char *licensePlate, const char *makeModel) : Vehicle(licensePlate, makeModel)
    {
        carwash = false;
    }
    Car::~Car()
    {
    }
    Car::Car(const Car &src) : Vehicle(src)
    {
        carwash = src.carwash;
    }
    Car &Car::operator=(const Car &src)
    {
        if (this != &src)
        {
            Vehicle::operator=(src);
            carwash = src.carwash;
        }
        return *this;
    }
    istream &Car::read(istream &istr)
    {
        if (isCsv())
        {
            Vehicle::read(istr);
            istr >> carwash;
            istr.ignore(1000, '\n');
        }
        else
        {
            cout << endl
                 << "Car information entry" << endl;
            Vehicle::read(istr);
            cout << "Carwash while parked? (Y)es/(N)o: ";
            string answer;
            getline(istr, answer);
            while (answer != "Y" && answer != "y" && answer != "N" && answer != "n")
            {
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                getline(istr, answer);
            }
            if(answer == "Y" || answer == "y")
                carwash = true;
            else
                carwash = false;
        }
        return istr;
    }
    ostream &Car::write(ostream &ostr) const
    {
        if (isEmpty())
        {
            ostr << "Invalid Car Object" << endl;
        }
        else
        {
            if (isCsv())
            {
                Vehicle::write(ostr);
                ostr << carwash << endl;
            }
            else
            {
                Vehicle::write(ostr);
                if (carwash)
                {
                    ostr << "With Carwash" << endl;
                }
                else
                {
                    ostr<<"Without Carwash"<<endl;
                }
            }
        }
        return ostr;
    }

    ostream &Car::writeType(ostream &ostr) const
    {
        if (isCsv())
        {
            ostr << "C,";
        }
        else
        {
            ostr << "Vehicle type: Car" << endl;
        }
        return ostr;
    }
}
