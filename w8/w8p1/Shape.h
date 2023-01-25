/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 17 November 2022
   Time - 3:00 pm
*/

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>

namespace sdds
{
    class Shape
    {
    public:
        virtual ~Shape() {}

        virtual void draw(std::ostream& ostr) const = 0;

        virtual void getSpecs(std::istream& istr) = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const Shape& src);
    std::istream& operator>>(std::istream& istr, Shape& src);
}

#endif