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
#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		std::vector<Vehicle*>::const_iterator it;
		for (it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
			(*it)->display(out);
			
			out << std::endl;
		}
	}
	Autoshop::~Autoshop()
	{
		std::vector<Vehicle*>::const_iterator it;
		for (it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
			delete* it;
		}
	}
}