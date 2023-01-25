/*
   Name - Kuldeepsinh Sandipsinh Mahida
   Email - kmahida1@myseneca.ca
   StudentID - 167547215
   Date of Completion - 11 November 2022 
   Time - 8:00 pm
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include "VehicleBasic.h"
#include "Dumper.h"
using namespace std;

namespace sdds
{
	VehicleBasic::VehicleBasic(const char* LP, int Year) {
		strcpy(licensePlate, LP);
		year = Year;
		strcpy(address, "Factory");
	}
	void VehicleBasic::NewAddress(const char* addr) {
		if (strcmp(address, addr) != 0) {
			cout << "|" << setw(8) << right << licensePlate << "| |" << setw(20) << right << address << " ---> " << setw(20) << left << addr << "|" << endl;
		}
		strcpy(address, addr);
	}

	std::istream& VehicleBasic::read(std::istream& in) {
		cout << "Built year: ";
		in >> year;

		cout << "License plate: ";
		in >> licensePlate;

		cout << "Current location: ";
		in >> address;

		return in;
	}

	std::ostream& VehicleBasic::write(std::ostream& os) {
		os << "| " << year << " | " << licensePlate << " | " << address;
		return os;
	}

	std::istream& operator >> (std::istream& in, VehicleBasic& vBasic) {
		return vBasic.read(in);
	}
	std::ostream& operator << (std::ostream& os, VehicleBasic vBasic) {
		return vBasic.write(os);
	}
	bool Dumper::unloadCargo() {
		if (currentCargoLoad != 0) {
			currentCargoLoad = 0;
			return true;
		}
		return false;
	}
	Dumper::Dumper(const char* LP, int Dumper_year, int Dumper_cap, const char* addr) : VehicleBasic(LP, Dumper_year) {
		capacity = Dumper_cap;
		NewAddress(addr);
		currentCargoLoad = 0;
	}
    std::istream& operator >> (std::istream& in, Dumper& dumper) {
		return dumper.read(in);
	}
	std::ostream& operator << (std::ostream& os, Dumper dumper) {
		return dumper.write(os);
	}
	bool Dumper::loaddCargo(double cargo) {
		double remainingCapacity = capacity - currentCargoLoad;
		if (cargo <= remainingCapacity) {
			currentCargoLoad += cargo;
			return true;
		}
		return false;
	}

	std::ostream& Dumper::write(std::ostream& os) {
		os << "| " << year << " | " << licensePlate << " | " << address;
		os << " | " << currentCargoLoad << "/" << capacity;
		return os;
	}
	std::istream& Dumper::read(std::istream& in) {
		cout << "Built year: ";
		in >> year;

		cout << "License plate: ";
		in >> licensePlate;

		cout << "Current location: ";
		in >> address;

		cout << "Capacity: ";
		in >> capacity;

		cout << "Cargo: ";
		in >> currentCargoLoad;

		return in;
	}

}