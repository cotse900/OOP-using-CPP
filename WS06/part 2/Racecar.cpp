/**************************************************
OOP345NFF Workshop 6
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 1 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)//default constructor
	{
		std::string localbooster;
		getline(in, localbooster);
		m_booster = std::stod(localbooster);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << '*';
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}