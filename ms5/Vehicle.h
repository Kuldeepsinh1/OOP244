/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 december 2022
time - 3:18 pm
*/

#ifndef SDDS_VEHICLE_H__ 
#define SDDS_VEHICLE_H__ 
#include "ReadWritable.h" 
#include <iostream> 
#include <string.h> 
#include <string> 

using namespace std;
namespace sdds { 
	class Vehicle : public ReadWritable {
	private:
		char* licenseplate{0};
		char* makemodel{0};
		int parkingspotnumber;
		
	protected:
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char*);

	public:
		Vehicle();
		Vehicle(const char*, const char*);
		~Vehicle();
		Vehicle(const Vehicle& src);
		Vehicle& operator=(const Vehicle& src);
		void setLicensePlate(const char*);
		int getParkingSpot() const;
		void setParkingSpot(int);
		bool operator==(const char*) const;
		bool operator==(const Vehicle&) const;
		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;
		virtual std::ostream& writeType(std::ostream&) const = 0;
	};
}
#endif
