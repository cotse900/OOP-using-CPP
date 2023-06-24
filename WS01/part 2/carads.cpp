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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "carads.h"

double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds
{
	static int counter = 0;
	Cars::Cars() : year(0), price(0.0), pDiscount(false) {}

	Cars::Cars(const Cars& src)
	{
		if (src) *this = src;
	}

	Cars& Cars::operator=(const Cars& src)
	{
		if (this != &src && src.brand != nullptr) {
			delete[] brand;
			brand = new char[strlen(src.brand) + 1];
			strcpy(brand, src.brand);
			strcpy(model, src.model);
			year = src.year;
			price = src.price;
			statusChar = src.statusChar;
			pDiscount = src.pDiscount;
		}
		return *this;
	}

	Cars::~Cars()
	{
		delete[] brand;
		brand = nullptr;
	}

	void Cars::read(std::istream& istr) {
		std::string localbrand;
		char applyDiscount{};
		if (istr) {
			istr >> statusChar;
			istr.ignore();

			std::getline(istr, localbrand, ',');

			if (localbrand.length() > 0) {
				delete[] brand;
				brand = new char[localbrand.length() + 1];
				strcpy(brand, localbrand.c_str());
			}

			istr.getline(model, 15, ',');
			istr >> year;
			istr.ignore();
			istr >> price;
			istr.ignore();
			istr >> applyDiscount;
			pDiscount = applyDiscount == 'Y' ? true : false;
			istr.ignore();
		}
	}
	void Cars::display(bool reset) const {
		std::cout.width(2);
		std::cout.setf(std::ios::left);
		std::cout.setf(std::ios::fixed);
		if (reset) {
			counter = 0;
		}
		std::cout << ++counter;
		std::cout << ". ";
		if (strlen(brand) > 0) {
			std::cout.width(10);
			std::cout << brand;
			std::cout << "| ";
			std::cout.width(15);
			std::cout << model;
			std::cout << "| ";
			std::cout.width(4);
			std::cout << year;
			std::cout << " |";
			std::cout.width(12);
			std::cout.setf(std::ios::right);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout << price + (price * g_taxrate);
			std::cout << "|";
			std::cout.unsetf(std::ios::right);

			if (pDiscount) {
				std::cout.setf(std::ios::right);
				std::cout.width(12);
				std::cout << (price + price * g_taxrate) * (1 - g_discount);
				std::cout.unsetf(std::ios::right);
				std::cout.unsetf(std::ios::fixed);
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "No Car" << std::endl;
		}
	}
	char Cars::getStatus() {
		return statusChar;
	}
	Cars::operator bool() const
	{
		return statusChar == 'N';
	}
	;
	void listArgs(int args, char* argv[]) {
		std::cout << "Command Line:\n" << "--------------------------" << std::endl;
		for (int i = 0; i < args; i++) {
			std::cout << "  " << (i + 1);
			std::cout << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------\n" << std::endl;
	}
	std::istream& operator>>(std::istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}
	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}
	;
}