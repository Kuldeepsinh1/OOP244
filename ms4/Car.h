/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 December 2022
time - 1:54pm
*/

#ifndef __SDDS_CAR_H__
#define __SDDS_CAR_H__

#include <iostream>
#include <string.h>
#include "Vehicle.h"

namespace sdds
{
    class Car: public Vehicle
    {
        bool carwash;
    public:
        Car();
        Car(const char * , const char* );
        ~Car();
        Car(const Car &);
        Car &operator=(const Car &);
        std::istream &read(std::istream &istr = std::cin);
        std::ostream &write(std::ostream &ostr = std::cout) const;
        std::ostream &writeType(std::ostream &ostr = std::cout) const;
    };
}

#endif