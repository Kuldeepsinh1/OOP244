/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 17 November 2022
   Time - 3:00 pm
*/

#include <iostream>
#include "Line.h"

using namespace std;

namespace sdds
{
    static int count = 0;

    void Line::getSpecs(std::istream& istr)
    {
        int _length;
        bool _escape = false;

        do {

            LblShape::getSpecs(istr);
            istr >> _length;

            if (!istr) {
                istr.clear();
                istr.ignore(32767, '\n');
            }
            else {

                istr.ignore();
                m_length = _length;
                _escape = true;
            }

        } while (!_escape);
    }

    void Line::draw(std::ostream& ostr) const
    {
        if (m_length > 0 && LblShape::label()) {

            ostr << LblShape::label();
            count++;
            if (count == 1) {
                ostr.width(m_length - 9);
            }
            else if (count == 6) {
                ostr.width(m_length - 10);
            }
            else if (count == 7) {
                ostr.width(m_length - 9);
            }
            else {
                ostr.width(m_length - 8);
            }
            ostr.fill('=');
            ostr << '=';

        }

    }
    Line::Line(const char* _label, int _length) : LblShape(_label)
    {
        if (_length > 0)
            m_length = _length;
    }
}
