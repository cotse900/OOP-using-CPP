/**************************************************
OOP345NFF Workshop 6
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 3 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		if (theVehicle != nullptr) {
			m_vehicles.push_back(theVehicle);
		}
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		for (auto v = m_vehicles.cbegin(); v != m_vehicles.cend(); v++) {
			(*v)->display(out);
			out << std::endl;
		}
	}
	Autoshop::~Autoshop()
	{
		for (auto v = m_vehicles.begin(); v != m_vehicles.end(); v++) {
			delete* v;
		}
	}
}