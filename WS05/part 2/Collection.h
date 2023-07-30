/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 13 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string nemCollection;
		T* arrayOfItems{};//a dynamically allocated array of items T
		size_t sizeArray{ 0 };
		void (*ptrToFunction)(const Collection<T>& addItem, const T& call) {
			nullptr
		};
		/*a pointer to a function that returns void and receives two parameters of type const Collection<T>&
		and const T& in that order.
		This is the observer function (it observes an event): when an item has been added to the collection,
		the class Collection<T> will call this function informing the client about the addition.
		https://www.learncpp.com/cpp-tutorial/function-pointers/
		initialize with {nullptr} or = nullptr*/
	public:
		Collection(const std::string& name) {
			nemCollection = name;
			arrayOfItems = nullptr;
			sizeArray = 0;
			ptrToFunction = nullptr;
		};
		Collection(Collection& nocopy) = delete;
		Collection& operator=(Collection& nocopy) = delete;
		~Collection() {
			delete[] arrayOfItems;
			arrayOfItems = nullptr;
		}
		const std::string& name() const {
			return nemCollection;
		}
		size_t size() const {
			return sizeArray;
		}
		/*stores the address of the callback function (observer) into an attribute.
		This parameter is a pointer to a function that returns void and accepts two parameters:
		a collection and an item that has just been added to the collection.
		This function is called when an item is added to the collection.*/
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			ptrToFunction = observer;
		};
		/*adds a copy of item to the collection, only if the collection doesn't contain an item with the same title.
		If item is already in the collection, this function does nothing.
		If the item is not yet in the collection, this function:
		resizes the array of items to accommodate the new item
		if an observer has been registered, this operator calls the observer function passing
		the current object (*this) and the new item as arguments.
		ASSUMPTION: type T has a member function called title() that returns the title of the item (std::string).
		*/
		Collection<T>& operator+=(const T& item) {
			bool found = false;
			for (size_t i = 0; i < sizeArray; i++) {
				if (arrayOfItems[i].title() == item.title()) {
					found = true;
				}
			}
			if (!found) {
				T* tempArray = new T[sizeArray + 1];
				for (size_t i = 0; i < sizeArray; i++) {
					tempArray[i] = arrayOfItems[i];
				}

				tempArray[sizeArray++] = item;
				delete[] arrayOfItems;
				arrayOfItems = tempArray;

				if (ptrToFunction != nullptr) {
					ptrToFunction(*this, item);
				}
			}
			return *this;
		};
		/*returns the item at index idx.
		if the index is out of range,
		this operator throws an exception of type std::out_of_range with the message Bad index [IDX].
		Collection has [SIZE] items. Use operator + to concatenate strings.
		*/
		T& operator[](size_t idx) const {
			size_t localsize = this->size();
			if (idx >= localsize) {
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(localsize) + "] items.");
			}
			else {
				return arrayOfItems[idx];
			}
		};
		/*returns the address of the item with the title title (type T has a member function called title() that
		returns the title of the item). If no such item exists, this function returns nullptr.
		*/
		T* operator[](const std::string& title) const {
			for (size_t i = 0; i < sizeArray; i++) {
				if (arrayOfItems[i].title() == title) {
					return &arrayOfItems[i];
				}
			}
			return nullptr;//if no item
		};
		friend std::ostream& operator<<(std::ostream& ostr, Collection& src) {
			for (size_t i = 0u; i < src.size(); i++) {
				ostr << src.arrayOfItems[i];
			}
			return ostr;
		};
	};
}

#endif //! SDDS_COLLECTION_H