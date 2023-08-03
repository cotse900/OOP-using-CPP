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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Vehicle.h"
#include "Car.h"
#include "Van.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif //!! SDDS_UTILITIES_H