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
#include "ReadWrite.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& os, const ReadWrite& c) 
    {
        return c.display(os);
    }

    istream& operator >> (istream& is, ReadWrite& c)
    {
        return c.read(is);
    }
}