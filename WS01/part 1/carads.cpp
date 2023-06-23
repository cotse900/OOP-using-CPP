/**************************************************
OOP345NFF Workshop 1
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 13 Sep 2022
I have done all the coding by myself and 
only copied the code that my professor 
provided to complete my workshops and assignments.
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "carads.h"

namespace sdds
{
	double g_taxrate = 0.0;
	double g_discount = 0.0;
	static int counter = 0; //Do not use global/member variables to store the counter!
	Cars::Cars() : year(0), price(0.0), pDiscount(false) {}

	void Cars::read(std::istream& istr) {
		char applyDiscount = false;
		if (istr) {
			istr >> statusChar;
			istr.ignore();
			istr.getline(brand, 10, ',');
			istr.getline(model, 15, ',');
			istr >> year;
			istr.ignore();
			istr >> price;
			istr.ignore();
			istr >> applyDiscount;
			if (applyDiscount == 'Y') {
				pDiscount = true;
			}
			else if (applyDiscount == 'N') {
				pDiscount = false;
			}
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
		if (*this) {
			std::cout.width(10);
			std::cout << brand;
			std::cout << "| ";
			std::cout.width(15);
			std::cout << model;
			std::cout << "| ";
			std::cout.width(4);
			std::cout << year;
			std::cout << " | ";
			std::cout.width(11);
			std::cout.setf(std::ios::right);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout << price + (price * g_taxrate);
			std::cout << "|";
			std::cout.unsetf(std::ios::right);
			std::cout.unsetf(std::ios::fixed);

			if (pDiscount) {
				std::cout.setf(std::ios::right);
				std::cout.setf(std::ios::fixed);
				std::cout.width(12);
				std::cout.precision(2);
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
		return brand[0];
	}
	;
	void listArgs(int args, char* argv[]) {
		std::cout << "Command Line:\n" << "--------------------------" << std::endl;
		for (int i = 0; i < args; i++) {
			std::cout.width(3);
			std::cout << (i + 1);
			std::cout << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------\n" << std::endl;
	};
}