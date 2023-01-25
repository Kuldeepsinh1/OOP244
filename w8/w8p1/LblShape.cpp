/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 17 November 2022
   Time - 3:00 pm
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"

using namespace std;

namespace sdds
{

    LblShape::LblShape(const char* _label)
    {
        if (_label && _label[0] != '\0') {
            m_label = new char[strlen(_label) + 1];
            strcpy(m_label, _label);
        }
    }
    LblShape::~LblShape()
    {
        if (m_label) {
            delete[] m_label;
            m_label = nullptr;
        }
    }
    const char* LblShape::label() const
    {
        return m_label;
    }

    void LblShape::getSpecs(std::istream& istr)
    {
        string _label;
        getline(istr, _label, ',');
        delete[] m_label;
        m_label = new char[strlen(_label.c_str()) + 1];
        strcpy(m_label, _label.c_str());
    }



}