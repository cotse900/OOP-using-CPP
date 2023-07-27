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
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Restaurant.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** reservationPtrs{};
		int numReservations{};
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& src);
		ConfirmationSender& operator=(const ConfirmationSender& src);
		ConfirmationSender(ConfirmationSender&& src);
		ConfirmationSender& operator=(ConfirmationSender&& src);
		~ConfirmationSender();
		operator bool() const;

		ConfirmationSender& operator+=(const Reservation&);
		ConfirmationSender& operator-=(const Reservation&);
		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& src);
	};
}

#endif // !SDDS_CONFIRMATIONSENDER_H