/*
                                          Workshop 10 
                                            Part 1

Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
E-mail:- kmahida1@myseneca.ca
Course:- OOP 244 
Submission Date:- 02/12/2022
Submission Time:- 11:18
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Car.h"
using namespace std;
namespace sdds
{
    Car::Car(const char* plate, const char* makeModel) 
    {
        set(plate, makeModel);
    }
    void Car::set(const char* plate, const char* makeModel) 
    {
        strncpy(plateNumber, plate, 8);
        plateNumber[8] = 0;
        strncpy(_makeModel, makeModel, 40);
        _makeModel[40] = 0;;
    }
    std::ostream& Car::display(std::ostream& os)const 
    {
        return os << plateNumber << " " << _makeModel;
    }
    std::istream& Car::read(std::istream& is) 
    {
        is >> plateNumber;
        is.getline(_makeModel, 40, '\n');
        return is;
    }
    bool Car::operator==(const char* mmSubstr)const 
    {
        return strstr(_makeModel, mmSubstr) != nullptr;
    }
}