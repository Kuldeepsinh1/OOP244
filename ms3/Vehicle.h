/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 27 november 2022
time - 7:18 pm
*/

#ifndef SDDS_VEHICLE_H__ 
#define SDDS_VEHICLE_H__ 
#include "ReadWritable.h" 
#include <iostream> 

using namespace std;
namespace sdds { 
	class Vehicle : public ReadWritable {
	private:
		char* licenseplate{0};
		char* makemodel{0};
		int parkingspotnumber; 

	public:
		Vehicle();
		Vehicle(const char*, const char*);
		~Vehicle();
		void setEmpty();
		bool isEmpty() const;
		const char* getLicensePlate() const;
		const char* getMakeModel() const;
		void setMakeModel(const char*);
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
