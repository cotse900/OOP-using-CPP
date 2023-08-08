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
#include <limits>
#include <sstream>
#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* instance{ nullptr };
		std::string read;
		char tag{};

		std::getline(in, read);
		std::stringstream sstr(read);
		sstr >> tag;
		sstr.seekg(0);
		if (!read.empty()) {
			
			if (tag == 'c' || tag == 'C') {
				instance = new Car(sstr);
			}
			else if (tag == 'r' || tag == 'R') {
				instance = new Racecar(sstr);
			}
			else if (tag == 'v' || tag == 'V') {
				instance = new Van(sstr);
			}
			else if (tag == 'l' || tag == 'L') {
				instance = new Luxuryvan(sstr);
			}
			else {
				throw std::string("Unrecognized record type: [") + tag + "]";
			}
		}


		return instance;
	}
}