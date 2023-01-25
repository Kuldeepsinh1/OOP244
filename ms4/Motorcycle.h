/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 December 2022
time - 1:54pm
*/

#ifndef __SDDS_MOTORCYCLE_H__
#define __SDDS_MOTORCYCLE_H__

#include <iostream>
#include <string.h>
#include "Vehicle.h"

namespace sdds
{
    class Motorcycle: public Vehicle
    {
        bool sidecar;
    public:
        Motorcycle();
        Motorcycle(const char *, const char *);
        ~Motorcycle();
        Motorcycle(const Motorcycle &);
        Motorcycle &operator=(const Motorcycle &);
        std::istream &read(std::istream &istr = std::cin);
        std::ostream &write(std::ostream &ostr = std::cout) const;
        std::ostream &writeType(std::ostream &ostr = std::cout) const;
    };
}

#endif