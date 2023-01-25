/*
   Name - Kuldeepsinh Sandipsinh Mahida
   StudentID - 167547215
   Email - kmahida1@myseneca.ca
   Date of Completion - 10 October 2022
   Time - 9:40 pm
*/

#include "TourBus.h"
#include <iostream>
#include <string>

using namespace std;

namespace sdds
{
	// This function is used to create the dynamic memory for the tickets
	TourBus::TourBus(int n)
	{
		seats = n;
		if (validTour())
		{
			ticket = new TourTicket[seats];

		}
		else
		{
			ticket = nullptr;
		}
	}
	
	// vaidates the tour only if seats are equal to 4,16,22

	bool TourBus::validTour()const
	{
		if (seats == 4 || seats == 16 || seats == 22)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// This function is used to board the passenger by issuing them the seat number
	const TourBus& TourBus::board()
	{
		cout << "Boarding " << seats << " Passengers:\n";
		for (int i = 0; i < seats; i++)
		{
			cout << i + 1 << "/" << seats << "- Passenger Name: ";
			char* name = new char[41];
			cin.getline(name, 41);
			ticket[i].issue(name);
			delete[] name;
		}
		return *this;
	}

	// This used to display the output of passengers details after validating the tickets
	void TourBus::startTheTour()const
	{
		if (ticket[0].valid())
		{
			cout << "Starting the tour....\n";
			cout << "Passenger List:\n";
			cout << "|Row | Passenger Name                           | Num |\n";
			cout << "+----+------------------------------------------+-----+\n";

			for (int i = 0; i < seats; i++)
			{
				cout << "|  " << i + 1 << " ";
				ticket[i].display();
				cout << endl;
			}
			cout << "+----+------------------------------------------+-----+\n";

		}
		else
		{
			cout << "Cannot start the tour, the bus is not fully boarded!\n";
		}
	}
	// this is used to delete the dynamic memory
	TourBus::~TourBus()
	{
		delete[] ticket;
	}

}