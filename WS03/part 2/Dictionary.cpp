/**************************************************
OOP345NFF Workshop 3
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 28 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <iostream>
#include "Dictionary.h"

namespace sdds
{
	Dictionary::Dictionary() {};
	std::ostream& Dictionary::write(std::ostream& ostr) const {
		ostr.width(20);
		ostr << m_term;
		ostr << ": " << m_definition;
		return ostr;
	};
	std::ostream& operator<<(std::ostream& ostr, const Dictionary& src) {
		src.write(ostr);
		return ostr;
	};
	bool Dictionary::operator==(const Dictionary& rhs) const
	{
		return m_term == rhs.m_term;
	};
}