
/*
   Name - Kuldeepsinh Sandipsinh Mahida
   StudentID - 167547215
   Email - kmahida1@myseneca.ca
   Date of Completion - 07 October 2022
   Time - 8:40 pm
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Seat.h" 
#include <iostream>  
#include <cstring> 
using namespace std; 
namespace sdds {

	// validating the rows and letter
	bool Seat::validate(int row, char letter)const 
	{
		if (row >= 1 && row <= 4) 
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (row >= 7 && row <= 15)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F' || letter == 'C' || letter == 'D')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (row >= 20 && row <= 38)
		{
			if (letter == 'A' || letter == 'B' || letter == 'E' || letter == 'F' || letter == 'C' || letter == 'D')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	
	// Saving the value in Current Object
	Seat& Seat::alAndCp(const char* str)
	{
		return *this;
	}

	int Seat::sizeCount(const char* msg)
	{
		int i;
		for (i = 0; msg[i] != '\0'; i++)
		{

		}
		return i;
	}
	
	// Setting the value to safe empty state
	Seat::Seat()
	{
		name = nullptr;
		num = 0;;
		word = 0;
	}

	// constructor passenger name
	Seat::Seat(const char* passengerName)
	{
		if (passengerName != nullptr && passengerName[0] != '\0')
		{
			name = new char[sizeCount(passengerName) + 1];
			strcpy(name, passengerName);
			num = 0;
			word = 0;
		}
		else
		{
			name = nullptr;
			num = 0;
			word = 0;
		}


	}
	
	// constructor for name ,row and letter
	Seat::Seat(const char* passengerName, int row, char letter)
	{
		if (passengerName != nullptr && passengerName[0] != '\0')
		{
			name = new char[sizeCount(passengerName) + 1];
			strcpy(name, passengerName);
			num = row;
			word = letter;
		}
		else
		{
			name = nullptr;
			num = 0;
			word = 0;
		}
	}
	
	// Reseting all the values to null and delallocating the dynamic memory
	Seat& Seat::reset()
	{
		delete[] name;
		name = nullptr;
		num = 0;;
		word = 0;
		return *this;
	}
	
	// checking the name is in safe empty state or not
	bool Seat::isEmpty() const
	{
		if (name == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool Seat::assigned() const
	{
		if (num != 0 && word != 0)
		{
			if (validate(num, word))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	// deallocating the constructor
	Seat::~Seat()
	{
		delete[] name;
		name = nullptr;

	}

	Seat& Seat::set(int row, char letter)
	{
		if (validate(row, letter))
		{
			num = row;
			word = letter;
		}
		else
		{
			num = row;
			word = letter;
		}
		return *this;
	}

	// retruning the rows number
	int Seat::row() const
	{
		return num;
	}

	// retruning the letter
	char Seat::letter()const
	{
		return word;
	}

	// retruning the passenger name
	const char* Seat::passenger()const
	{
		return name;
	}

	// displaying the values
	ostream& Seat::display(ostream& countRef) const
	{
		if (name != nullptr) 
		{

			int i;

			for (i = 0; i < 40 && name[i] != '\0'; i++)
			{
				countRef << name[i];
			}
			while (i < 40)
			{
				countRef << ".";
				i += 1;
			}
			countRef << " ";
			if (validate(num, word))
			{
				countRef << num << word;
			}
			else
			{
				countRef << "___";
			}
		}
		else
		{
			countRef << "Invalid Seat!";
		}
		return countRef;
	}

	istream& Seat::read(istream& cinRef)
	{
		delete[] name;
		name = new char[71];
		cinRef.getline(name, 71, ',');
		cinRef >> num;
		cinRef >> word;
		cinRef.ignore();
		return cinRef;
	}
}