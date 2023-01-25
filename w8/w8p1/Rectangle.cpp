/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 17 November 2022
   Time - 3:00 pm
*/
#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds
{

    Rectangle::Rectangle(const char* _label, int _width, int _height) : LblShape(_label)
    {
        int _compareWidth = strlen(LblShape::label()) + 2;
        if (_width > _compareWidth && _height > 3) {
            m_width = _width;
            m_height = _height;
        }
    }

    void Rectangle::getSpecs(std::istream& istr)
    {
        int _width;
        int _height;
        char _comma;
        bool _escape = false;
        do {
            LblShape::getSpecs(istr);
            istr >> _width >> _comma >> _height;

            if (!istr) {
                istr.clear();
                istr.ignore(32767, '\n');
            }
            else {
                istr.ignore();
                m_width = _width;
                m_height = _height;
                _escape = true;
            }
        } while (!_escape);

    }
    void Rectangle::draw(std::ostream& ostr) const
    {
        if (m_width > 0 && m_height >> 0) {
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+' << endl;

            ostr << '|';
            ostr.width(m_width - 2);
            ostr.fill(' ');
            ostr << left << LblShape::label() << '|' << endl;
            for (unsigned int i = 0; i < (m_height - 3); i++) {
                ostr << '|';
                ostr.width(m_width - 2);
                ostr.fill(' ');
                ostr << ' ' << '|' << endl;
            }
            ostr << '+';
            ostr.width(m_width - 2);
            ostr.fill('-');
            ostr << '-' << '+';
        }
    } // namespace sdds


}