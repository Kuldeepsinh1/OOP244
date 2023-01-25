/*
Name:- Kuldeepsinh Sandipsinh Mahida
Student ID:- 167547215
submission date  - 7 December 2022
time - 1:54pm
*/

#define _CRT_SECURE_NO_WARNINGS 
#include "Vehicle.h" 
#include <cctype>
#include <cstring> 
#include <iostream> 

using namespace std; 
namespace sdds { 
	Vehicle::Vehicle()
	{
		setEmpty();
	}
	Vehicle::Vehicle(const char* licensePlate, const char* makeModel): ReadWritable()
	{
		if (licensePlate && makeModel && strlen(makeModel) >= 2 && strlen(licensePlate) > 0 && strlen(licensePlate) <= 8) {
			parkingspotnumber = 0;
			setLicensePlate(licensePlate);
			setMakeModel(makeModel);
		}
		else {
			setEmpty();
		}

	}
	Vehicle::~Vehicle() {
		delete[] licenseplate;
		delete[] makemodel;
	}
	Vehicle::Vehicle(const Vehicle& src)
	{
		makemodel = nullptr;
		setEmpty();
		*this = src;
	}

	Vehicle& Vehicle::operator=(const Vehicle& src)
	{
		if (this != &src)
		{
			// call copy constructor of ReadWritable
			ReadWritable::operator=(src);
			if (makemodel != nullptr)
			{
				delete[] makemodel;
				makemodel = nullptr;
			}
			if (licenseplate != nullptr)
			{
				delete[] licenseplate;
				licenseplate = nullptr;
			}
			if (src.licenseplate != nullptr)
			{
				licenseplate = new char[strlen(src.licenseplate) + 1];
				strcpy(licenseplate, src.licenseplate);
			}
			
			if (src.makemodel != nullptr)
			{
				makemodel = new char[strlen(src.makemodel) + 1];
				strcpy(makemodel, src.makemodel);
			}
			parkingspotnumber = src.parkingspotnumber;
		}
		return *this;
	}
	void Vehicle::setEmpty()
	{
        delete[] licenseplate;
        delete[] makemodel;
		licenseplate = nullptr;
		makemodel = nullptr;
		parkingspotnumber = -1;
	}
	bool Vehicle::isEmpty() const
	{
		if (parkingspotnumber < 0) {
			return true;
		}
		return false;
	}
	const char* Vehicle::getLicensePlate() const
	{
		return licenseplate;
	}
	const char* Vehicle::getMakeModel() const
	{
		return makemodel;
	}
	void Vehicle::setMakeModel(const char* makeModel)
	{
		if (makeModel && strlen(makeModel) >= 2) {
			delete[] makemodel;
			makemodel = new char[strlen(makeModel) + 1];
			strcpy(makemodel, makeModel);
		}
		else {
			setEmpty();
		}

	}
	void Vehicle::setLicensePlate(const char* licensePlate)
	{
		delete[] licenseplate;
		licenseplate = new char[strlen(licensePlate) + 1];
		strcpy(licenseplate, licensePlate);
		for (int i = 0; licenseplate[i]; i++) {
			licenseplate[i] = toupper(licenseplate[i]);
		}
	}

	int Vehicle::getParkingSpot() const
	{
		return parkingspotnumber;
	}
	void Vehicle::setParkingSpot(int parkingSpot)
	{
		//cout << parkingspotnumber << "hi";

		if (parkingSpot >= 0) {
			parkingspotnumber = parkingSpot;
			//cout << parkingspotnumber<<"hi";
		}
		else {
			setEmpty();
		}
	}
	bool Vehicle::operator==(const char* licensePlate) const
	{
		bool isEqual = true;
		if (licenseplate && licensePlate && (strlen(licenseplate) == strlen(licensePlate))) {
                        int licensePlateLen = strlen(licenseplate);
			for (int i = 0; i < licensePlateLen; i++) {
				if (toupper(licenseplate[i]) != toupper(licensePlate[i])) {
					isEqual = false;
					break;
				}
			}
		}
		else {
			isEqual = false;
		}
		return isEqual;
	}
	bool Vehicle::operator==(const Vehicle& secondVehicle) const
	{
		return secondVehicle == licenseplate;
	}
	std::istream& Vehicle::read(std::istream& istr)
	{
		int m_parkingSpotNumber = 0;

		char tempLic[10];
		char tempMModel[62];

		if (isCsv()) {
			istr >> m_parkingSpotNumber;
			istr.ignore();
			istr.get(tempLic, 9, ',');
			istr.ignore(1024, ',');
			istr.get(tempMModel, 61, ',');
			istr.ignore(1024, ',');
		}
		else {
			cout << "Enter License Plate Number: ";
			istr.get(tempLic, 10);
			istr.ignore(1024, '\n');
			while (strlen(tempLic) > 8) {
				cout << "Invalid License Plate, try again: ";
				istr.get(tempLic, 10);
				istr.ignore(1024, '\n');
			}
			cout << "Enter Make and Model: ";
			istr.get(tempMModel, 62);
			istr.ignore(1024, '\n');
			while (strlen(tempMModel) > 60 || strlen(tempMModel) < 2) {
				cout << "Invalid Make and model, try again: ";
				istr.get(tempMModel, 62);
				istr.ignore(1024, '\n');
			}
		}
		if (istr.fail()) {
			setEmpty();
			istr.clear();
		}
		else {
			setMakeModel(tempMModel);
			setParkingSpot(m_parkingSpotNumber);
			setLicensePlate(tempLic);
		}
		return istr;
	}
	std::ostream& Vehicle::write(std::ostream& ostr) const
	{
		if (isEmpty()) {
			ostr << "Invalid Vehicle Object" << endl;
		}
		else {
			writeType(ostr);
			if (isCsv()) {			
				
					ostr << parkingspotnumber << "," << licenseplate << "," << makemodel << ",";
			}
			else {
			    ostr << "Parking Spot Number: ";
				if (parkingspotnumber == 0) {
					ostr << "N/A";

				}
				else {
					ostr << parkingspotnumber;

				}
				ostr << endl;

				ostr << "License Plate: " << licenseplate << endl;

				ostr << "Make and Model: " << makemodel << endl;
			}
		}
		return ostr;
	}
}
