/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 4 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
		size_t numReservations{};
		Reservation** reservationPtrs{};
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& src);
		Restaurant& operator=(const Restaurant& src);
		Restaurant(Restaurant&& src);
		Restaurant& operator=(Restaurant&& src);
		virtual ~Restaurant();
		operator bool() const;
		size_t size() const;

		friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& src);
	};
}

#endif // !SDDS_RESTAURANT_H