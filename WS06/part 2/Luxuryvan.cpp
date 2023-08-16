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
#include "Luxuryvan.h"

namespace sdds
{
	Luxuryvan::Luxuryvan(std::istream& in) : Van (in)
	{
		std::string localvan;
		getline(in, localvan);
		localvan = trim(localvan);
		if (localvan[0] != 'e') {//Luxury van is e/electric only
			throw std::string("Invalid record!");
		}
		m_consumption = localvan;
	}
	void Luxuryvan::display(std::ostream& out) const
	{
		Van::display(out);
		out << (m_consumption[0] == 'e' ? " electric van  *" : "");
	}
	std::string Luxuryvan::consumption() const
	{
		return m_consumption;
	}
}