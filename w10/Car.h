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

#include <iostream>
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "ReadWrite.h"
namespace sdds 
{
    class Car : public ReadWrite
    {
        char plateNumber[9];
        char _makeModel[41];
    public:
        Car(const char* plate = "", const char* makeModel = "");
        void set(const char* plate, const char* makeModel);
        std::ostream& display(std::ostream& os)const;
        std::istream& read(std::istream& is);
        bool operator==(const char* mmSubstr)const;
    };


}
#endif // !SDDS_CAR_H_