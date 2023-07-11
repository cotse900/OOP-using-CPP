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
#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include <iostream>
#include <string>

namespace sdds
{
	struct TennisMatch
	{
		std::string tourneyID{};
		std::string tourneyName{};
		unsigned matchID{};//the order here is important or main func can't read properly
		std::string winner{};
		std::string loser{};
		operator bool() const;//for insertion operator
	};

	std::ostream& operator<<(std::ostream& ostr, const TennisMatch& src);

	class TennisLog
	{
		TennisMatch* m_Match{};
		size_t numMatches{};

	public:
		TennisLog();
		TennisLog(const char* filename);
		TennisLog(const TennisLog& src);//rule of 3 applies in part 1
		TennisLog& operator=(const TennisLog& src);
		TennisLog(TennisLog&& src);
		TennisLog& operator=(TennisLog&& src);//rule of 5 applies in part 2
		~TennisLog();

		void addMatch(const TennisMatch& match);
		TennisLog findMatches(const char* name);
		TennisMatch operator[](size_t index) const;
		operator size_t() const;

	};

}

#endif // !SDDS_TENNISLOG_H