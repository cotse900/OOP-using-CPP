/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 6 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <iostream>
#include "ConfirmationSender.h"

namespace sdds
{
	/*In ConfirmationSender, each element of an array points to an original of Reservations
	Use original addresses to initialize value(address) of each element here*/
	ConfirmationSender::ConfirmationSender()
	{
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src)
	{
		if (src) {
			*this = src;
		}
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src)
	{
		if (this != &src) {
			delete[] reservationPtrs;
			numReservations = src.numReservations;
			reservationPtrs = new const Reservation * [numReservations] {};
			for (int i = 0; i < numReservations; i++) {
				reservationPtrs[i] = src.reservationPtrs[i];
			}
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src)
	{
		operator=(std::move(src));
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src)
	{
		if (this != &src) {
			delete[] reservationPtrs;
			numReservations = src.numReservations;
			reservationPtrs = src.reservationPtrs;
			src.numReservations = 0;
			src.reservationPtrs = nullptr;
		}
		return *this;
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] reservationPtrs;
		reservationPtrs = nullptr;
	}
	ConfirmationSender::operator bool() const
	{
		return reservationPtrs;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool addressInArray = false;
		for (int i = 0; i < numReservations; i++) {
			if (&res == reservationPtrs[i])
				addressInArray = true;
		}
		if (!addressInArray) {
			const Reservation** resizeArray = new const Reservation * [numReservations + 1];
			for (int i = 0; i < numReservations; i++) {
				resizeArray[i] = reservationPtrs[i];
			}
			resizeArray[numReservations] = &res;
			delete[] reservationPtrs;
			reservationPtrs = resizeArray;
			numReservations++;

		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		if (numReservations > 0) {
			bool addressInArray = false;
			int i = 0;
			for (i = 0; i < numReservations; i++) {
				if (&res == reservationPtrs[i]) {
					reservationPtrs[i] = nullptr;
					addressInArray = true;

				}
			}
			if (addressInArray) {
				const Reservation** resizeArray = new const Reservation * [numReservations - 1];
				//new
				i--;
				--numReservations;
				for (int j = i; j < numReservations; j++) {
					reservationPtrs[j] = reservationPtrs[j + 1];
				}
				for (int j = 0; j < numReservations; j++) {
					resizeArray[j] = reservationPtrs[j];
				}
				delete[] reservationPtrs;
				reservationPtrs = resizeArray;

			}
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& src)
	{
		ostr << "--------------------------" << std::endl;
		ostr << "Confirmations to Send" << std::endl;
		ostr << "--------------------------" << std::endl;
		if (src.numReservations != 0) {
			for (int i = 0; i < src.numReservations; i++) {
				if (src.reservationPtrs[i] != nullptr) {
					ostr << *src.reservationPtrs[i];
				}
			}
		}
		else {
			ostr << "There are no confirmations to send!" << std::endl;
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}
}