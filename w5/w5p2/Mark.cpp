/*
name - Kuldeepsinh Sandipsinh Mahida
Student id - 167547215
Email - kmahida1@myseneca.ca
Date of completion 21 october 2022
time - 8:00 pm
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds
{
    Mark::Mark() {
         marks = 0;
    }
    Mark::Mark(int m)
    {
        marks = m;
    }

    Mark::operator int() const
    {
       if (marks >= 0 && marks <= 100) {
            return this->marks;
       }
       else {
           return 0;
       }
    }

    Mark::operator double() const
    {
        if (marks >= 0 && marks < 50)
        {
            return 0.0;
        }
        else if (marks >= 50 && marks < 60)
        {
            return 1.0;
        }
        else if (marks >= 60 && marks < 70)
        {
            return 2.0;
        }
        else if (marks >= 70 && marks < 80)
        {
            return 3.0;
        }
        else if (marks >= 80 && marks <= 100)
        {
            return 4.0;
        }
        else {
            return 0;
        }
    }

    Mark::operator char() const
    {
        if (marks >= 0 && marks < 50)
        {
            return 'F';
        }
        else if (marks >= 50 && marks < 60)
        {
            return 'D';
        }
        else if (marks >= 60 && marks < 70)
        {
            return 'C';
        }
        else if (marks >= 70 && marks < 80)
        {
            return 'B';
        }
        else if (marks >= 80 && marks <= 100)
        {
            return 'A';
        }
        else {
            return 'X';
        }
    }

    Mark::operator bool() const
    {
        if (marks >= 0 && marks <= 100) {
            return true;
        }
        else {
            return false;
        }
    }
 
    bool operator>(const Mark& leftmarks, const Mark& rightmarks)
    {
        return (leftmarks.marks > rightmarks.marks);
    }

    bool operator<(const Mark& leftmarks, const Mark& rightmarks)
    {
        return (leftmarks.marks < rightmarks.marks);
    }

    bool operator>=(const Mark& leftmarks, const Mark& rightmarks)
    {
        return (leftmarks.marks >= rightmarks.marks);
    }

    bool operator<=(const Mark& leftmarks, const Mark& rightmarks)
    {
        return (leftmarks.marks <= rightmarks.marks);
    }

    bool operator==(const Mark& leftmarks, const Mark& rightmarks)
    {
        return (leftmarks.marks == rightmarks.marks);
    }

    bool operator!=(const Mark& leftmarks, const Mark& rightmarks)
    {
        return (leftmarks.marks != rightmarks.marks);
    }

    Mark& Mark::operator--()
    {
        if (marks >= 0 && marks <= 100) {
            --marks;
            return *this;
        }
        return *this;
    }

    Mark Mark::operator--(int) {
        if (marks >= 0 && marks <= 100) {
            Mark mark = *this;
            marks--;
            return mark;
        }
        return *this;
    }

    Mark& Mark::operator++()
    {
        if (marks >= 0 && marks <= 100) {
            ++marks;
        }
        return *this;
    }

    Mark Mark::operator++(int) {
        if (marks >= 0 && marks <= 100) {
            Mark mark = *this;
            marks++;
            return mark;
         }
        return *this;
    }

    bool Mark::operator~() {
        if (marks >= 50 && *this) {
            return true;
        }
        return false;
    }

    Mark& Mark::operator+=(const int k)
    {
        if (*this) {
            marks += k;
        }
        return *this;
    }

    Mark& Mark::operator-=(const int k)
    {
        if (*this) {
            marks -= k;
        }
        return *this;
    }

    int operator+=(int& value, const Mark& rightmarks)
    {
        if (rightmarks.marks >= 0 && rightmarks.marks <= 100) {
            value = value + rightmarks.marks;
            return value;
        }
        return value;
    }

    int operator-=(int& value, const Mark& rightmarks)
    {
        if (rightmarks.marks >= 0 && rightmarks.marks <= 100) {
            value = value - rightmarks.marks;
            return value;
        }
        return value;
    }



    Mark operator+(const Mark& leftmarks, const int value)
    {
        int currentMarks = leftmarks.marks;
        int marks = currentMarks + value;
        Mark mark(marks);
        return mark;
    }

    int operator+(const int value, const Mark& rightmarks)
    {
        int currentMarks = rightmarks.marks;
        int Marks = currentMarks + value;
        return Marks;
    }

    Mark operator+(const Mark& leftmarks, const Mark& rightmarks)
    {
        int Marks = leftmarks.marks + rightmarks.marks;
        Mark mark(Marks);
        return mark;
    }


    Mark& Mark::operator<<(Mark& rhs)
    {
        this->marks += rhs.marks;
        rhs.marks = 0;
        return *this;
    }

    Mark& Mark::operator>>(Mark& rhs)
    {
        rhs.marks = this->marks;
        this->marks = 0;
        return *this;
    }

}
