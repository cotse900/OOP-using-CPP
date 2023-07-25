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
#include <iostream>
#include "Restaurant.h"

namespace sdds
{
	/*In Restaurant, each element of the array points to a copy of Reservations
	Use copies of each pointed Reservation and point them by DMA

	Verbally, it is this:
	const Reservation** reservationPtrs >>>> const Reservation* pointer1, 2, 3... N >>>> Reservation Reservation1, 2, 3... N
	In other words, **reservationPtrs points to an array of pointers which points to Reservations. Restaurant deals with copies of Reservations whereas ConfirmationSender deals with originals of Reservations.
	*/
	Restaurant::Restaurant(const Reservation* Reservations[], size_t count) : numReservations{ count }{
		reservationPtrs = new Reservation * [numReservations];
		for (size_t i = 0; i < numReservations; i++) {
			reservationPtrs[i] = new Reservation(*Reservations[i]);
		}
		numReservations = count;
	}
	Restaurant::Restaurant(const Restaurant& src)
	{
		if (src) {
			*this = src;
		}
	}
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		if (this != &src) {
			for (size_t i = 0; i < numReservations; i++) {
				delete reservationPtrs[i];
			}
			delete[] reservationPtrs;

			numReservations = src.numReservations;

			reservationPtrs = new Reservation * [size()];
			for (size_t i = 0; i < size(); i++) {
				reservationPtrs[i] = new Reservation(*src.reservationPtrs[i]);
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& src)
	{
		operator=(std::move(src));
	}
	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (this != &src) {
			for (size_t i = 0; i < numReservations; i++) {
				delete reservationPtrs[i];
			}
			delete[] reservationPtrs;

			numReservations = src.numReservations;

			reservationPtrs = src.reservationPtrs;

			src.numReservations = 0;

			src.reservationPtrs = nullptr;
		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		for (size_t i = 0; i < numReservations; i++) {
			delete reservationPtrs[i];
		}
		delete[] reservationPtrs;
		reservationPtrs = nullptr;
	}
	Restaurant::operator bool() const
	{
		return reservationPtrs;
	}
	size_t Restaurant::size() const
	{
		return numReservations;
	}
	std::ostream& operator<<(std::ostream& ostr, const Restaurant& src)
	{
		static int CALL_CNT = 0;
		ostr << "--------------------------" << std::endl;
		ostr << "Fancy Restaurant (" << ++CALL_CNT << ")" << std::endl;
		ostr << "--------------------------" << std::endl;

		if (src.reservationPtrs != nullptr) {
			for (size_t i = 0; i < src.size(); i++) {
				ostr << *src.reservationPtrs[i];
			}
		}
		else {
			ostr << "This restaurant is empty!" << std::endl;
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}
}