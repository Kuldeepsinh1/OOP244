/*
   Name - Kuldeepsinh Sandipsinh Mahida
   StudentID - 167547215
   Email - kmahida1@myseneca.ca
   Date of Completion - 16 October 2022
   Time - 11:00 pm
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "Apartment.h" 

using namespace std;
namespace sdds
{
	Apartment::Apartment(int number, double balance)
	{

		if (number >= 1000 && number <= 9999
			&& balance >= 0)
		{
			m_Num = number;
			m_balance = balance;
		}
	}
	std::ostream& Apartment::display() const
	{
		if (*this)
		{
			cout.width(4);
			cout << m_Num;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		}
		else
		{
			cout << "Invld|  Apartment   ";
		}
		return cout;
	}// 

	Apartment::operator bool() const {
		if (this->m_Num >= 1000 && this->m_Num <= 9999 && this->m_balance >= 0) {
			return true;
		}

		return false;
	}

	Apartment::operator int() const {
		return this->m_Num;
	}

	Apartment::operator double() const {
		return this->m_balance;
	}

	bool Apartment::operator~()const
	{
		if (this->m_balance < 0.00001) {
			return true;
		}
		return false;
	}

	Apartment& Apartment::operator=(const int apt_num) {
		if (apt_num >= 1000 && apt_num <= 9999)
		{
			this->m_Num = apt_num;
		}
		else {
			this->m_Num = -1;
			this->m_balance = 0.0;
		}
		return *this;
	}

	Apartment& Apartment::operator=(Apartment& rhs) {

		double temp_balance = this->m_balance;
		int temp_number = this->m_Num;

		this->m_balance = rhs.m_balance;
		this->m_Num = rhs.m_Num;

		rhs.m_balance = temp_balance;
		rhs.m_Num = temp_number;

		return *this;
	}

	Apartment& Apartment::operator+=(const double result) {
		if (*this && result >= 0) {
			this->m_balance += result;
		}
		return *this;
	}

	Apartment& Apartment::operator-=(const double result)
	{
		if (*this && this->m_balance >= result && result >= 0) {

			this->m_balance -= result;
		}
		return *this;
	}

	Apartment& Apartment::operator<<(Apartment& rhs)
	{
		if (this->m_Num != rhs.m_Num && rhs.operator bool() && *this) {
			this->m_balance += rhs.m_balance;
			rhs.m_balance = 0;
		}
		return *this;
	}

	Apartment& Apartment::operator>>(Apartment& rhs)
	{
		if (this->m_Num != rhs.m_Num && rhs.operator bool() && *this) {
			rhs.m_balance += this->m_balance;
			this->m_balance = 0;
		}
		return *this;
	}

	double operator+(const Apartment& lhs, const Apartment& rhs)
	{
		if (lhs.operator bool() && rhs.operator bool()) {
			double value = 0;
			value = lhs.m_balance + rhs.m_balance;
			return value;
		}
		return 0;
	}


	double operator+=(double& result, const Apartment& rhs)
	{
		result = result + rhs.m_balance;
		return result;
	}

}