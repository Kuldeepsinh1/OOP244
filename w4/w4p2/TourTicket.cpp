/***********************************************************************
// OOP244 Workshop 4 p2: TourTicket Module
//
// File	TourTicket.cpp
// Version 1.0
// Date	2022/09/27
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

/*
   Name - Kuldeepsinh Sandipsinh Mahida
   StudentID - 167547215
   Email - kmahida1@myseneca.ca
   Date of Completion - 10 October 2022
   Time - 9:40 pm
*/

#include <iostream>
#include "TourTicket.h"
using namespace std;
namespace sdds {
    int next_ticketNumber = 100;
    void TourTicket::copyName(const char* str) {
        int i = 0;
        for (i = 0; i < 40 && str[i]; m_name[i] = str[i], i++);
        m_name[i] = 0;
    }
    TourTicket::TourTicket() {
        m_name[0] = char(0);
        m_ticketNumber = -1;
    }
    TourTicket& TourTicket::issue(const char* passengerName) {
        if (passengerName && passengerName[0]) {
            copyName(passengerName);
            m_ticketNumber = next_ticketNumber++;
        }
        return *this;
    }
    std::ostream& TourTicket::display(std::ostream& coutRef) const {
        if (valid()) {
            cout << "| ";
            coutRef.width(40);
            coutRef.setf(ios::left);
            coutRef << m_name << " | " << m_ticketNumber << " |";
            coutRef.unsetf(ios::left);
        }
        else {
            coutRef << "Invalid TourTicket information" << endl;
        }
        return coutRef;
    }
    bool TourTicket::valid() const {
        return bool(m_name[0]);
    }
}