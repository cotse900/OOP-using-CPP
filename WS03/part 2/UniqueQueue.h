/**************************************************
OOP345NFF Workshop 3
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 28 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <iostream>
#include <cmath>
#include "Queue.h"

namespace sdds
{
	//no item appears more than once
	template<typename T>//one template para T
	class UniqueQueue : public Queue<T, 100u>
	{
	public:
		bool push(const T& item);//override
		~UniqueQueue() {};
	};
	//ensure that the numbers are "identical" if the difference between them is 0.005 or less
	template <typename T>
	bool UniqueQueue<T>::push(const T& item) {
		for (unsigned i = 0; i < Queue<T, 100u>::size(); i++) {
			if (Queue<T, 100u>::operator[](i) == item)
				return false;
		}

		Queue<T, 100u>::push(item);
		return true;
	}
	//prevent adding an item if it already exists in the UniqueQueue
	template <>
	bool UniqueQueue<double>::push(const double& item) {
		for (unsigned i = 0; i < Queue<double, 100u>::size(); i++) {
			if (std::fabs(Queue<double, 100u>::operator[](i) - item) <= 0.005)//https://en.cppreference.com/w/cpp/numeric/math/fabs
				return false;
		}

		Queue<double, 100u>::push(item);
		return true;
	}
}

#endif // !SDDS_UNIQUEQUEUE_H