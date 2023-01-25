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
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
    class ReadWrite {
    public:
        virtual std::ostream& display(std::ostream& os)const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual ~ReadWrite() {
        }
    };
    std::ostream& operator<<(std::ostream& os, const ReadWrite& c);
    std::istream& operator>>(std::istream& is, ReadWrite& c);
}
#endif // !SDDS_READWRITE_H_
