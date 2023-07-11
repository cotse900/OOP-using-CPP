/**************************************************
OOP345NFF Workshop 2
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 21 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include "Timer.h"

namespace sdds
{
	void Timer::start()
	{
		startT = std::chrono::steady_clock::now();
	}

	long long Timer::stop()
	{
		endT = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<std::chrono::nanoseconds>(endT - startT).count();
	}
}

