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
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>
#include "Dictionary.h"

namespace sdds
{
	template<typename T, unsigned CAPACITY>
	class Queue
	{
		T numObjects[CAPACITY]{};
		const static T dummyObject;//This object will be returned by member-functions when the client requests an object that is not in the queue.
		//can be assumed const since they are default values anyway
		unsigned numElements{};//initialize!
	
	public:
		virtual ~Queue();
		virtual bool push(const T& item);//mutator
		T pop();//mutator

		unsigned size() const;//query
		void display(std::ostream& ostr = std::cout) const;//query
		T operator[](size_t index) const; //query
	};

	template<typename T, unsigned CAPACITY>
	Queue<T, CAPACITY>::~Queue() {}

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
		T popThisThing;
		if (numElements > 0) {
			popThisThing = numObjects[0];
			numElements--;//decrement to take out last index of dictionary content
			for (unsigned i = 0; i < numElements; i++) {
				numObjects[i] = numObjects[i + 1];//copy "new" array over to old
			}
		}
		else {
			popThisThing = dummyObject;
		}
		return popThisThing;
	}
	//https://stackoverflow.com/questions/59110221/c-linked-list-with-template-how-to-create-pop
	//https://www.geeksforgeeks.org/implementing-stack-using-class-templates-in-cpp/
	//https://www.geeksforgeeks.org/queue-linked-list-implementation/

	template<typename T, unsigned CAPACITY>
	unsigned Queue<T, CAPACITY>::size() const {
		return numElements;
	}

	template<typename T, unsigned CAPACITY>
	void Queue<T, CAPACITY>::display(std::ostream& ostr) const {
		ostr << "----------------------" << std::endl;
		ostr << "| Dictionary Content |" << std::endl;
		ostr << "----------------------" << std::endl;
		for (unsigned i = 0; i < numElements; i++) {
			ostr << numObjects[i] << std::endl;
		}
		ostr << "----------------------" << std::endl;
	}

	template<typename T, unsigned CAPACITY>
	T Queue<T, CAPACITY>::operator[](size_t index) const {
		if (index >= 0 && index < numElements) {
			return numObjects[index];
		}
		else return dummyObject;
	}

	//Specialize the class - member object when type T = Dictionary and CAPACITY = 100u so the term is "Empty Term" and the definition is "Empty Substitute".
	
	//default value as empty
	template <typename T, unsigned CAPACITY>
	const T Queue<T, CAPACITY>::dummyObject{};

	//default values as "Empty Term", "Empty Substitute"
	template <>
	const Dictionary Queue<Dictionary, 100u>::dummyObject{ "Empty Term", "Empty Substitute" };

}

#endif // !SDDS_QUEUE_H