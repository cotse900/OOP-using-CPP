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
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "CrimeStatistics.h"

namespace sdds
{
	std::string CrimeStatistics::trim(std::string& str)
	{
		if (str.length() > 0) {
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}
	CrimeStatistics::CrimeStatistics(std::string filename)
	{
		std::ifstream file(filename);
		if (!file) {
			throw "ERROR: cannot open the file!";
		}
		else {
			std::string local;
			Crime base;
			while (file) {
				std::getline(file, local, '\n');
				if (!local.empty()) {
					base.province = local.substr(0, 25);
					local = local.erase(0, 25);
					trim(base.province);
					base.district = local.substr(0, 25);
					local = local.erase(0, 25);
					trim(base.district);
					base.crime = local.substr(0, 25);
					local = local.erase(0, 25);
					trim(base.crime);

					base.year = stoi(local.substr(0, 5));
					local = local.erase(0, 5);
					base.numCases = stoi(local.substr(0, 5));
					local = local.erase(0, 5);
					base.numResolved = stoi(local.substr(0, 5));
					local = local.erase(0, 5);

					m_cases.push_back(base);
				}
			}
			file.close();
		}
	}
	void CrimeStatistics::display(std::ostream& out) const
	{
		std::for_each(m_cases.begin(), m_cases.end(), [&out](const Crime& base) {
			out << base;
			});
	}
	std::ostream& operator<<(std::ostream& out, const Crime& base)
	{
		out << "| " << std::left << std::setw(21) << base.province;
		out << " | " << std::setw(15) << base.district;
		out << " | " << std::setw(20) << base.crime;

		out << " | " << std::right << std::setw(6) << base.year;
		out << " | " << std::setw(4) << base.numCases;
		out << " | " << std::setw(3) << base.numResolved << " |" << std::endl;
		return out;
	}
}