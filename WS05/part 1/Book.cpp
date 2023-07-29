/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 11 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

namespace sdds
{
	const std::string& Book::title() const
	{
		return titleBk;
	}
	const std::string& Book::country() const
	{
		return countryPub;
	}
	const size_t& Book::year() const
	{
		return yearPub;
	}
	double& Book::price()
	{
		return priceBk;
	}
	std::string Book::trim(std::string& str, const char delimiter)
	//removes leading and trailing space up to delimiter
	{
		std::string temp = str;
		std::string localstr = "";
		localstr = temp.substr(0, temp.find(delimiter));
		localstr.erase(0, localstr.find_first_not_of(' '));
		localstr.erase(localstr.find_last_not_of(' ') + 1);
		return localstr;
	}
	Book::Book(const std::string& strBook)
	{
		std::string str = strBook;//takes in an entire txt line, then stores the tokens and erase them one by one
		std::string localauthor, localtitle, localcountry, localprice, localyear, localdescription;

		localauthor = trim(str, ',');
		authorBk = localauthor;
		str.erase(0, str.find(",") + 1);

		localtitle = trim(str, ',');
		titleBk = localtitle;
		str.erase(0, str.find(",") + 1);

		localcountry = trim(str, ',');
		countryPub = localcountry;
		str.erase(0, str.find(",") + 1);

		localprice = trim(str, ',');
		priceBk = std::stod(localprice);
		str.erase(0, str.find(",") + 1);

		localyear = trim(str, ',');
		yearPub = std::stoi(localyear);
		str.erase(0, str.find(",") + 1);

		localdescription = trim(str, '\n');
		description = localdescription;
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& book)
	{
		ostr.setf(std::ios::right);
		ostr << std::setw(20) << book.authorBk << " | ";
		ostr << std::setw(22) << book.title() << " | ";
		ostr << std::setw(5) << book.country() << " | ";
		ostr << std::setw(4) << book.year() << " | ";
		ostr.setf(std::ios::fixed);
		ostr << std::setw(6) << std::setprecision(2) << book.priceBk << " | ";
		ostr << book.description;
		ostr << std::endl;
		return ostr;
	}
}