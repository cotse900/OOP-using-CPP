/**************************************************
OOP345NFF Workshop 6
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 31 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string carMaker{};
		std::string carCondition{};
		double carTopSpeed{ 0.0 };
	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;
		std::string trim(std::string&);
	};
}

#endif //!! SDDS_CAR_H