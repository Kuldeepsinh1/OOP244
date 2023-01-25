/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 11 November 2022
   Time - 8:00 pm
*/

#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>

namespace sdds
{
	const int LICENSE_PLATE_SIZE = 10;
	const int SIZE_OF_ADDRESS = 65;
	class VehicleBasic {
	protected:
		char licensePlate[LICENSE_PLATE_SIZE];
		char address[SIZE_OF_ADDRESS];
		int year;
	
	public:
		VehicleBasic(const char* LP, int Year);
		void NewAddress(const char* addr);
		std::ostream& write(std::ostream& os);
		std::istream& read(std::istream& in);

		friend std::istream& operator >> (std::istream& in, VehicleBasic& vBasic);
		friend std::ostream& operator << (std::ostream& os, VehicleBasic vBasic);

	};
}

#endif