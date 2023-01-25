/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 17 November 2022
   Time - 3:00 pm
*/

#include <iostream>
#include "Shape.h"

namespace sdds
{
    std::ostream& operator<<(std::ostream& ostr, const Shape& src)
    {
        src.draw(ostr);
        return ostr;
    }
    std::istream& operator>>(std::istream& istr, Shape& src)
    {
        src.getSpecs(istr);
        return istr;
    }

}