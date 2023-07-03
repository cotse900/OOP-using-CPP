/**************************************************
OOP345NFF Workshop 3
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 25 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include <iostream>
#include <string>

namespace sdds
{
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() {
			return m_term;
		}
		const std::string& getDefinition() {
			return m_definition;
		}
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{};
		Dictionary();
		std::ostream& write(std::ostream& ostr) const;
		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.
	};
	std::ostream& operator<<(std::ostream& ostr, const Dictionary& src);
}

#endif // !SDDS_DICTIONARY_H