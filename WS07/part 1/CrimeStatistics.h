/**************************************************
OOP345NFF Workshop 7
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 6 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H
#include <iostream>
#include <vector>
#include <string>

namespace sdds
{
	struct Crime
	{
		std::string province{};
		std::string district{};
		std::string crime{};
		size_t year{}, numCases{}, numResolved{};
	};
	class CrimeStatistics
	{
		std::vector<Crime> m_cases;
	public:
		std::string trim(std::string&);
		CrimeStatistics(std::string filename);
		void display(std::ostream& out) const;

	};
	std::ostream& operator<<(std::ostream& out, const Crime&);
}

#endif //!! SDDS_CRIMESTATISTICS_H