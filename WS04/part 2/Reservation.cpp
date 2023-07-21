/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 3 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Reservation.h"

namespace sdds
{

	Reservation::Reservation() : reservationID{ "" }, reservationNem{ "" },
		email{ "" }, noOfPeople{ 0 }, expectDay{ 0 }, expectTime{ 0 }
	{};
	Reservation::Reservation(const std::string& res) {
		std::string line = res;//first, get in the txt line
		std::string localid, localnem, localemail, localparty, localday, localtime;//ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
		//ID
		localid = line.substr(0, line.find(":"));//locate this id up to :
		trim(localid);
		line = line.erase(0, line.find(":") + 1);	
		strcpy(reservationID, localid.c_str());
		//name
		localnem = line.substr(0, line.find(","));
		trim(localnem);
		line = line.erase(0, line.find(",") + 1);
		reservationNem = localnem;
		//email
		localemail = line.substr(0, line.find(","));
		trim(localemail);
		line = line.erase(0, line.find(",") + 1);
		email = localemail;
		//party
		localparty = line.substr(0, line.find(","));
		trim(localparty);
		line = line.erase(0, line.find(",") + 1);
		noOfPeople = std::stoi(localparty);//must cast for int items
		//day
		localday = line.substr(0, line.find(","));
		trim(localday);
		line = line.erase(0, line.find(",") + 1);
		expectDay = std::stoi(localday);
		//time
		localtime = line;
		localtime.erase(0, localtime.find_first_not_of(' '));
		expectTime = std::stoi(localtime);
	};
	Reservation::~Reservation() {

	};
	void Reservation::update(int day, int time) {
		expectDay = day;
		expectTime = time;
	}
	std::string& Reservation::trim(std::string& trimThisStr) const
	{
		while (trimThisStr[0] == ' ') {//erases leading space
			trimThisStr.erase(0, trimThisStr.find_first_not_of(' '));
		}
		while (trimThisStr[trimThisStr.size() - 1] == ' ') {//removes trailing space
			trimThisStr.erase(trimThisStr.find_last_not_of(' ') + 1);
		}
		return trimThisStr;
	}
	;
	std::ostream& operator<<(std::ostream& ostr, const Reservation& src) {
		ostr << "Reservation ";
		//ID
		ostr.setf(std::ios::right);
		ostr.width(10);
		ostr << src.reservationID << ": ";
		//name
		ostr.width(20);
		ostr << src.reservationNem;
		ostr.unsetf(std::ios::right);
		//email
		ostr << "  <" << src.email << "> ";
		for (int i = src.email.length(); i <= 20; i++) {
			ostr << " ";
		}

		//the rest
		if (src.expectTime >= 6 && src.expectTime <= 9) {
			ostr << "Breakfast";
		}
		else if (src.expectTime >= 11 && src.expectTime <= 15) {
			ostr << "Lunch";
		}
		else if (src.expectTime >= 17 && src.expectTime <= 21) {
			ostr << "Dinner";
		}
		else {
			ostr << "Drinks";
		}
		ostr << " on day " << src.expectDay << " @ " << src.expectTime << ":00 for ";
		if (src.noOfPeople == 1) {
			ostr << src.noOfPeople << " person.";
		}
		else {
			ostr << src.noOfPeople << " people.";
		}
		ostr << std::endl;
		return ostr;
	};
}