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
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>

namespace sdds
{
	class Timer
	{
		std::chrono::steady_clock::time_point startT;
		std::chrono::steady_clock::time_point endT;

	public:
		void start();
		long long stop();
	};
}


#endif // !SDDS_TIMER_H