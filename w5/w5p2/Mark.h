/*
name - Kuldeepsinh Sandipsinh Mahida
Student id - 167547215
Email - kmahida1@myseneca.ca
Date of completion 21 october 2022
time - 8:00 pm
 */
#pragma once
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
    class Mark
    {
    private:
        int marks = 0;

    public:
        Mark();
        Mark(int m);

        operator int() const;
        operator double() const;
        operator char() const;
        operator bool() const;

        friend bool operator>(const Mark& l_marks, const Mark&);
        friend bool operator<(const Mark& l_marks, const Mark&);
        friend bool operator>=(const Mark& l_marks, const Mark&);
        friend bool operator<=(const Mark& l_marks, const Mark&);
        friend bool operator==(const Mark& l_marks, const Mark&);
        friend bool operator!=(const Mark& l_marks, const Mark&);

        Mark& operator --();
        Mark operator --(int);

        Mark& operator ++();
        Mark operator ++(int);

        bool operator~();

        Mark& operator+=(const int);
        Mark& operator-=(const int);

        friend int operator+=(int& value, const Mark&);
        friend int operator-=(int& value, const Mark&);

        friend Mark operator+(const Mark& l_marks, const int);
        friend int operator+(const int value, const Mark&);
        friend Mark operator+(const Mark& l_marks, const Mark&);

        Mark& operator<<(Mark&);
        Mark& operator>>(Mark&);
    };
}

#endif
