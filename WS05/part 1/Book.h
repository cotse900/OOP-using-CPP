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
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>

namespace sdds
{
	class Book
	{
		std::string authorBk{};
		std::string titleBk{};
		std::string countryPub{};
		size_t yearPub{ 0 };
		double priceBk{ 0 };
		std::string description{};
	public:
		Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		std::string trim(std::string& str, const char delimiter);
		Book(const std::string& strBook);
		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
	};
}

#endif //! SDDS_BOOK_H