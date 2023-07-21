/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 3 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>

const int id_size{ 11 };//the ID on the reservation should display on a field of size 10, aligned to the right

namespace sdds
{
	class Reservation
	{
		char reservationID[id_size];//an array of characters
		std::string reservationNem;
		std::string email;
		int noOfPeople;
		int expectDay;//the day is an integer between 1 and 28
		int expectTime;//the hour is an integer between 1 and 24

	public:
		Reservation();
		Reservation(const std::string& res);
		virtual ~Reservation();
		void update(int day, int time);
		std::string& trim(std::string&) const;

		friend std::ostream& operator<<(std::ostream& ostr, const Reservation& src);
	};
}

#endif // !SDDS_RESERVATION_H