/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 17 November 2022
   Time - 3:00 pm
*/

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds
{
    class Rectangle : public LblShape
    {
        unsigned int m_width{ 0 };
        unsigned int m_height{ 0 };
    public:
        Rectangle() {}
        Rectangle(const char* _label, int _width, int _height);
        virtual ~Rectangle() {}
        void getSpecs(std::istream& istr);
        /*
      Rectangle(const Rectangle &src) = delete;
      */
        void draw(std::ostream& ostr) const;
    };
}
#endif