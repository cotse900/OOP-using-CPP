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
#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include "Vehicle.h"

namespace sdds
{
	class Van : public Vehicle
	{
		std::string vanMaker{};
		std::string vanType{};
		std::string vanPurpose{};
		std::string vanCondition{};
		double vanTopSpeed{ 0.0 };
	public:
		Van(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;
		void display(std::ostream&) const;
		std::string trim(std::string&);
	};
}

#endif //!! SDDS_VAN_H