/*
   Name - Kuldeepsinh Sandipsinh Mahida
   StudentID - 167547215
   Email - kmahida1@myseneca.ca
   Date of Completion - 10 October 2022
   Time - 9:40 pm
*/

#ifndef _SDDS_TOUR_BUS_H_
#define _SDDS_TOUR_BUS_H_
#include "TourTicket.h"

namespace sdds
{

	class TourBus
	{
	private:
		int seats;
		TourTicket* ticket;
	public:
		TourBus(int num);
		bool validTour()const;
		const TourBus& board();
		void startTheTour()const;
		~TourBus();
	};
}
#endif // !_SDDS_TOUR_BUS_H_
