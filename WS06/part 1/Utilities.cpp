/**************************************************
OOP345NFF Workshop 6
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 31 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <limits>
#include "Utilities.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* instance{ nullptr };
		char tag{};
		in >> tag;
		if (in.good()) {
			in.ignore(std::numeric_limits<std::streamsize>::max(), ',');

			if (tag == 'c' || tag == 'C') {
				instance = new Car(in);
			}
			else if (tag == 'v' || tag == 'V') {
				instance = new Van(in);
			}
		}


		return instance;
	}
}