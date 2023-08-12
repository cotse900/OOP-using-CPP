/**************************************************
OOP345NFF Workshop 6
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 3 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds
{
	Car::Car(std::istream& istr)
	{
		std::string str;

		//tag: dealt with in utilities, not here
		std::getline(istr, str, ',');

		//maker
		std::getline(istr, str, ',');
		carMaker = trim(str);
		//condition
		std::getline(istr, str, ',');
		carCondition = trim(str);

		if (carCondition == "n" || carCondition == "")
			carCondition = "new";
		else if (carCondition == "u")
			carCondition = "used";
		else if (carCondition == "b")
			carCondition = "broken";
		else {
			throw std::string("Invalid record!");
		}
		//top_speed
		std::getline(istr, str, ',');
		try {
			carTopSpeed = std::stod(str);
		}
		catch (std::invalid_argument& error)
		{
			throw std::string("Invalid record!");
		}
	}
	std::string Car::condition() const
	{
		return carCondition;
	}
	double Car::topSpeed() const
	{
		return carTopSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| " << std::right << std::setw(10) << carMaker;
		out << " | " << std::left << std::setw(6) << condition();
		out << " | " << std::fixed << std::setprecision(2) << std::setw(6) << topSpeed() << " |";
	}
	std::string Car::trim(std::string& str)
	{
		if (str.length() > 0) {
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}
}