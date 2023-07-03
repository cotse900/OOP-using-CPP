/**************************************************
OOP345NFF Workshop 3
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 26 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>
#include "Dictionary.h"

namespace sdds
{
	//tip: can do Collection first before Pair
	template<typename T, unsigned CAPACITY>
	class Queue
	{
		T numObjects[CAPACITY]{};
		unsigned numElements{};//initialize!
		T dummyObject{};

	public:
		virtual ~Queue();
		virtual bool push(const T& item);//mutator
		virtual T pop();//mutator

		unsigned size();//query
		void display(std::ostream& ostr = std::cout);//query
		virtual T operator[](size_t index); //query
	};

	template<typename T, unsigned CAPACITY>
	Queue<T, CAPACITY>::~Queue() {
		//needed for part 2
	}

	template<typename T, unsigned CAPACITY>
	bool Queue<T, CAPACITY>::push(const T& item) {
		bool result = false;
		if (numElements < CAPACITY) {
			numObjects[numElements++] = item;
			result = true;
		}
		return result;
	}

	template<typename T, unsigned CAPACITY>
	T Queue<T, CAPACITY>::pop()
		//pop(): a mutator that removes the first member of the queue.
		//It creates a temporary copy of it and then shifts the rest of the queue elements forward by one index.
		//This function returns a copy of the removed object.
	{
		T popThisThing = numObjects[CAPACITY - 1];
		return popThisThing;
	}
	//https://stackoverflow.com/questions/59110221/c-linked-list-with-template-how-to-create-pop
	//https://gist.github.com/Panchatcharam/bce3e1cbc38f870cab93458276f02a2b
	//https://www.geeksforgeeks.org/implementing-stack-using-class-templates-in-cpp/
	//https://www.geeksforgeeks.org/queue-linked-list-implementation/

	template<typename T, unsigned CAPACITY>
	unsigned Queue<T, CAPACITY>::size() {
		return numElements;
	}

	template<typename T, unsigned CAPACITY>
	void Queue<T, CAPACITY>::display(std::ostream& ostr) {
		ostr << "----------------------" << std::endl;
		ostr << "| Dictionary Content |" << std::endl;
		ostr << "----------------------" << std::endl;
		for (unsigned int i = 0; i < numElements; i++) {
			ostr << numObjects[i] << std::endl;

		}
		ostr << "----------------------" << std::endl;
	}

	template<typename T, unsigned CAPACITY>
	T Queue<T, CAPACITY>::operator[](size_t index) {
		if (index >= 0 && index <= CAPACITY - 1) {
			return numObjects[index];
		}
		else return dummyObject;
	}

	template<>//Specialize the class - member object when type T = Dictionary and CAPACITY = 100u so the term is "Empty Term" and the definition is "Empty Substitute".
	Dictionary Queue<Dictionary, 100u>::operator[](size_t index) {
		if (index >= 0 && numElements > 0 && index <= numElements - 1) {
			return numObjects[index];
		}
		else return dummyObject = Dictionary("Empty Term", "Empty Substitute");
	}
}

#endif // !SDDS_QUEUE_H