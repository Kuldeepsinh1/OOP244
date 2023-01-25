/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 17 November 2022
   Time - 3:00 pm
*/
#ifndef SDDS_Lblshape_H_
#define SDDS_Lblshape_H_

#include "Shape.h"

namespace sdds
{
    class LblShape : public Shape
    {
        char* m_label{ nullptr };
    protected:
        const char* label() const;
    public:
        LblShape() {}
        LblShape(const char* _label);
        virtual ~LblShape();
        LblShape(const LblShape& src) = delete;
        LblShape& operator=(const LblShape& src) = delete;
        void getSpecs(std::istream& istr);
    };
}
#endif