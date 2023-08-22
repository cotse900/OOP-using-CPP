/**************************************************
OOP345NFF Workshop 7
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 12 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <fstream>
#include <algorithm>
#include <numeric>
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
					base.m_resolved = stoi(local.substr(0, 5));
					local = local.erase(0, 5);

					m_cases.push_back(base);
				}
			}
			file.close();
		}
	}
	//changed all lambdas to pass by value except ostream/display
	// 
	//the lambdas should capture the necessary variables from context only by value
	//(the stream object is the only one allowed to be captured by reference)
	void CrimeStatistics::display(std::ostream& out) const
	{
		std::for_each(m_cases.cbegin(), m_cases.cend(), [&out](const Crime base) {
			out << base << std::endl;
			});
		//T accumulate(InputIt first, InputIt last, T init, BinaryOperation op)
		auto totalCases = std::accumulate(m_cases.cbegin(), m_cases.cend(), 0, [](auto count, const Crime base) -> auto {
			return count + base.numCases;
		});
		auto totalResolved = std::accumulate(m_cases.cbegin(), m_cases.cend(), 0, [](auto count, const Crime base) -> auto {
			return count + base.m_resolved;
		});
		out.width(89);
		out.fill('-');
		out << '\n';
		out.fill(' ');
		out << "| ";
		out.width(77);
		out << std::right << "Total Crimes:";
		out.width(7);
		out << totalCases << " |" << std::endl;
		out << "| ";
		out.width(77);
		out << std::right << "Total Resolved Cases:";
		out.width(7);
		out << totalResolved << " |" << std::endl;
	}
	void CrimeStatistics::sort(const std::string field)
	{
		if (field == "Province") {
			std::sort(m_cases.begin(), m_cases.end(), [](const Crime& case1, const Crime case2) -> bool {
				return case1.province < case2.province;
				});
		}
		else if (field == "Crime") {
			std::sort(m_cases.begin(), m_cases.end(), [](const Crime& case1, const Crime case2) -> bool {
				return case1.crime < case2.crime;
				});
		}
		else if (field == "Cases") {
			std::sort(m_cases.begin(), m_cases.end(), [](const Crime& case1, const Crime case2) -> bool {
				return case1.numCases < case2.numCases;
				});
		}
		else if (field == "Resolved") {
			std::sort(m_cases.begin(), m_cases.end(), [](const Crime& case1, const Crime case2) -> bool {
				return case1.m_resolved < case2.m_resolved;
				});
		}
	}
	//takes out [None]
	void CrimeStatistics::cleanList()
	{
		std::transform(m_cases.cbegin(), m_cases.cend(), m_cases.begin(), [](Crime base) {
			base.crime == "[None]" ? base.crime = " " : base.crime;
			return base;
			});
	}
	bool CrimeStatistics::inCollection(const std::string crime) const
	{
		auto found = std::find_if(m_cases.begin(), m_cases.end(), [=](const Crime base)->bool {
			return crime == base.crime;
			});
		return found != m_cases.end();
	}
	std::list<Crime> CrimeStatistics::getListForProvince(const std::string province) const
	{
		/*count_if and copy_if version
		* ~292 allocs
		*/
		size_t num = std::count_if(m_cases.begin(), m_cases.end(), [=](const Crime base)->bool {
			return province == base.province;
			});
		std::list<Crime> howMany(num);
		std::copy_if(m_cases.begin(), m_cases.end(), howMany.begin(), [=](const Crime base)->bool {
			return province == base.province;
			});
		return howMany;

		//also possible: resize and distance
	}
	std::ostream& operator<<(std::ostream& out, const Crime& base)
	{
		out << "| " << std::left;
		out.width(21);
		out << base.province;
		out << " | ";
		out.width(15);
		out << base.district;
		out << " | ";
		out.width(20);
		out << base.crime;

		out << " | " << std::right;
		out.width(6);
		out << base.year;
		out << " | ";
		out.width(4);
		out << base.numCases;
		out << " | ";
		out.width(3);
		out << base.m_resolved << " |";//updated

		return out;
	}
}