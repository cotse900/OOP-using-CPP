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
#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

namespace sdds
{
	Movie::Movie() : titleMovie{ "" }, yearMovie{ 0 }, desc{ "" }{

	}
	const std::string& Movie::title() const
	{
		return titleMovie;
	}
	std::string Movie::trim(std::string& str, const char delimiter)//copy from Book
	{
		std::string temp = str;
		std::string localstr = "";
		localstr = temp.substr(0, temp.find(delimiter));
		localstr.erase(0, localstr.find_first_not_of(' '));
		localstr.erase(localstr.find_last_not_of(' ') + 1);
		return localstr;
	}
	Movie::Movie(const std::string& strMovie)
	{
		std::string str = strMovie;
		std::string localtitle, localyear, localdescription;

		localtitle = trim(str, ',');
		titleMovie = localtitle;
		str.erase(0, str.find(",") + 1);

		localyear = trim(str, ',');
		yearMovie = std::stoi(localyear);
		str.erase(0, str.find(",") + 1);

		localdescription = trim(str, '\n');
		desc = localdescription;
	}
	std::ostream& operator<<(std::ostream& ostr, const Movie& movie)
	{
		ostr.setf(std::ios::right);
		ostr.width(40);
		ostr << movie.title() << " | ";
		ostr.width(4);
		ostr << movie.yearMovie << " | ";
		ostr.unsetf(std::ios::right);
		ostr << movie.desc << std::endl;
		return ostr;
	}
}