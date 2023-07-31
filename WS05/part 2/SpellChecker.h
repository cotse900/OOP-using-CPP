/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 10 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>

namespace sdds
{
	const size_t max_word = 6;
	class SpellChecker
	{
		std::string m_badWords[max_word];
		std::string m_goodWords[max_word];
		size_t count[max_word]{ 0 };//for use in operator() and showStatistics
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif //! SDDS_SPELLCHECKER_H
