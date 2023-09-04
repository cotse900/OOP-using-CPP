/**************************************************
OOP345NFF Workshop 8
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 16 Nov 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool validateSIN(const std::string num) {
			int length = num.length();
			int sum = std::stoi(num.substr(length - 1, 1));
			int parity = (length - 2) % 2;
			int digit{};
			for (int i = 0; i <= length - 2; i++) {
				digit = std::stoi(num.substr(i, 1));
				if ((i % 2) == parity)
					digit *= 2;
				if (digit > 9)
					digit -= 9;
				sum += digit;
			}

			return sum % 10 == 0;
		}
		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(const std::unique_ptr<T>& object) {
			list.push_back(*object);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T* object) {
			list.push_back(*object);
		}
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
