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
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "ReadWrite.h"
namespace sdds {
    class Student : public ReadWrite {
        int _stno;
        char _name[41];
    public:
        Student();
        Student(int stno, const char* name);
        void set(int stno, const char* name);
        std::ostream& display(std::ostream& os)const;
        std::istream& read(std::istream& is);
        bool operator==(const char* nameSubstr)const;
    };
}
#endif // !SDDS_STUDENT_H_