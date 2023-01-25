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
#include <iomanip>
#include <cstring>
using namespace std;
#include "Employee.h"
namespace sdds 
{
    Employee::Employee() 
    {
        set(0, "", 0.0);
    }
    Employee::Employee(int stno, const char* name, double salary) 
    {
        set(stno, name, salary);
    }
    void Employee::set(int stno, const char* name, double salary)
    {
        _empno = stno;
        strcpy(_name, name);
        _salary = salary;
    }
    ostream& Employee::display(ostream& os)const
    {
        return os << _empno << " " << _name << ", " << setprecision(2) << fixed << _salary;
    }
    istream& Employee::read(istream& is) 
    {
        is >> _empno;
        is.getline(_name, 40, ',');
        is >> _salary;
        return is;
    }
    bool Employee::operator==(const char* nameSubstr)const
    {
        return strstr(_name, nameSubstr) != nullptr;
    }
}