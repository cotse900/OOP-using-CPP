/**************************************************
OOP345NFF Workshop 6
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 1 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <iostream>
#include <iomanip>
#include "Van.h"

namespace sdds
{
	Van::Van(std::istream& istr)
	{
		std::string str;

		//tag: dealt with in utilities, not here
		std::getline(istr, str, ',');

		//maker
		std::getline(istr, str, ',');
		vanMaker = trim(str);
		//type
		std::getline(istr, str, ',');
		vanType = trim(str);

		if (vanType == "p")
			vanType = "pickup";
		else if (vanType == "m")
			vanType = "mini-bus";
		else if (vanType == "c")
			vanType = "camper";
		else {
			throw std::string("Invalid record!");
		}
		//purpose
		std::getline(istr, str, ',');
		vanPurpose = trim(str);

		if (vanPurpose == "d")
			vanPurpose = "delivery";
		else if (vanPurpose == "p")
			vanPurpose = "passenger";
		else if (vanPurpose == "c")
			vanPurpose = "camping";
		else {
			throw std::string("Invalid record!");
		}
		//condition
		std::getline(istr, str, ',');
		vanCondition = trim(str);

		if (vanCondition == "n" || vanCondition == "")
			vanCondition = "new";
		else if (vanCondition == "u")
			vanCondition = "used";
		else if (vanCondition == "b")
			vanCondition = "broken";
		else {
			throw std::string("Invalid record!");
		}
		//top_speed
		std::getline(istr, str, ',');
		try {
			vanTopSpeed = std::stod(str);
		}
		catch (std::invalid_argument& error) {
			throw std::string("Invalid record!");
		}
	}
	std::string Van::condition() const
	{
		return vanCondition;
	}
	double Van::topSpeed() const
	{
		return vanTopSpeed;
	}
	std::string Van::type() const
	{
		return vanType;
	}
	std::string Van::usage() const
	{
		return vanPurpose;
	}
	void Van::display(std::ostream& out) const
	{
		out << "| " << std::right << std::setw(8) << vanMaker;
		out << " | " << std::left << std::setw(12) << vanType;
		out << " | " << std::setw(12) << vanPurpose;
		out << " | " << std::setw(6) << condition();
		out << " | " << std::fixed << std::setprecision(2) << std::setw(6) << topSpeed() << " |";
	}
	std::string Van::trim(std::string& str)
	{
		if (str.length() > 0) {
			str.erase(0, str.find_first_not_of(' '));
			str.erase(str.find_last_not_of(' ') + 1);
		}
		return str;
	}
}