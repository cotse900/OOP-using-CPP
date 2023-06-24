/**************************************************
OOP345NFF Workshop 1
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 15 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef CARADS_H
#define CARADS_H
#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds
{

	class Cars
	{
		char* brand{};
		char model[15]{};
		int year{};
		double price{};
		char statusChar{};
		bool pDiscount;

	public:
		Cars();
		Cars(const Cars& src);
		Cars& operator=(const Cars& src);
		~Cars();
		void read(std::istream& istr);
		void display(bool reset) const;
		char getStatus();
		operator bool() const;//part 2
	};
	void listArgs(int args, char* argv[]);
	std::istream& operator>>(std::istream& is, Cars& car);//has the same functionality as Cars::read().
	void operator>>(const Cars& car1, Cars& car2);//copies in the second parameter the content of the first parameter.
}

#endif //! CARADS_H_