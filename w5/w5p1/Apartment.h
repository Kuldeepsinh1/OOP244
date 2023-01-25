/*
   Name - Kuldeepsinh Sandipsinh Mahida
   StudentID - 167547215
   Email - kmahida1@myseneca.ca
   Date of Completion - 16 October 2022
   Time - 11:00 pm
*/
#ifndef SDDS_APARTMENT_H_ 
#define SDDS_APARTMENT_H_ 
#include <iostream> 

namespace sdds
{
	class Apartment
	{
		int m_Num = -1;
		double m_balance = 0.0;

	public: // public
		Apartment(int num, double balance);
		std::ostream& display()const;

		operator bool() const;
		operator int() const;
		operator double() const;

		bool operator~() const;

		Apartment& operator=(const int apt_num);
		Apartment& operator=(Apartment& rhs);

		Apartment& operator+=(const double result);
		Apartment& operator-=(const double result);

		Apartment& operator<<(Apartment& rhs);
		Apartment& operator>>(Apartment& rhs);

		friend double operator+(const Apartment& lhs, const Apartment& rhs);
		friend double operator+=(double& result, const Apartment& rhs);

	};

}

#endif // SDDS_APARTMENT_H_