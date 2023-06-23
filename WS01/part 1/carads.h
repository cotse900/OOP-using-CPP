/**************************************************
OOP345NFF Workshop 1
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 11 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef CARADS_H
#define CARADS_H
#include <iostream>
namespace sdds
{
	extern double g_taxrate;
	extern double g_discount;
	class Cars
	{
		char brand[10]{};
		char model[15]{};
		int year{};
		double price{};
		char statusChar{};
		bool pDiscount;

	public:
		Cars();
		void read(std::istream& istr);
		void display(bool reset) const;
		char getStatus();
		operator bool() const;
	};
	void listArgs(int args, char* argv[]);
}

#endif //! CARADS_H_