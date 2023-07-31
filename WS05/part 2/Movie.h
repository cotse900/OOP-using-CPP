/**************************************************
OOP345NFF Workshop 4
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 10 Oct 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>

namespace sdds
{
	class Movie
	{
		std::string titleMovie{};
		size_t yearMovie{ 0 };
		std::string desc{};
	public:
		Movie();
		const std::string& title() const;
		std::string trim(std::string& str, const char delimiter);
		Movie(const std::string& strMovie);

		template <typename T>
		void fixSpelling(T& spellChecker) {//calls the overloaded operator() on instance spellChecker, passing to it the movie title and description
			spellChecker(titleMovie);
			spellChecker(desc);
		}

		friend std::ostream& operator<<(std::ostream& ostr, const Movie& movie);
	};
}

#endif //! SDDS_MOVIE_H