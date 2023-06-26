/**************************************************
OOP345NFF Workshop 2
Professor : Hong Huang
Student   : Chungon Tse
ID        : 154928188
Completed : 20 Sep 2022
I have done all the coding by myself and
only copied the code that my professor
provided to complete my workshops and assignments.
**************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
#include "TennisLog.h"

namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const TennisMatch& src)
	{
		if (src) {//bool
			ostr.fill('.');
			ostr.width(23);//temporarily changed to 23; sounds like an issue with main func
			ostr << std::right;
			ostr << "Tourney ID : ";
			ostr.width(30);
			ostr << std::left;
			ostr << src.tourneyID << std::endl;

			ostr.width(23);
			ostr << std::right;
			ostr << "Match ID : ";
			ostr.width(30);
			ostr << std::left;
			ostr << src.matchID << std::endl;

			ostr.width(23);
			ostr << std::right;
			ostr << "Tourney : ";
			ostr.width(30);
			ostr << std::left;
			ostr << src.tourneyName << std::endl;

			ostr.width(23);
			ostr << std::right;
			ostr << "Winner : ";
			ostr.width(30);
			ostr << std::left;
			ostr << src.winner << std::endl;

			ostr.width(23);
			ostr << std::right;
			ostr << "Loser : ";
			ostr.width(30);
			ostr << std::left;
			ostr << src.loser << std::endl;
		}
		else {
			ostr << "Empty Match";
		}
		return ostr;
	}

	TennisLog::TennisLog()
	{
		m_Match = nullptr;
		numMatches = 0;
	}

	TennisLog::TennisLog(const char* filename)
	{
		std::ifstream file(filename);
		size_t numLines = 0;
		std::string localstr{};

		if (file) {
			std::getline(file, localstr);

			while (file) {
				std::getline(file, localstr);
				numLines++;//read total number of lines
			}
			//numMatches--;
			m_Match = new TennisMatch[numLines];

			file.clear();
			file.seekg(0);

			std::getline(file, localstr);
			while (file) {
				std::getline(file, localstr, ',');
				if (file) {
					m_Match[numMatches].tourneyID = localstr;
					std::getline(file, localstr, ',');

					m_Match[numMatches].tourneyName = localstr;
					std::getline(file, localstr, ',');

					m_Match[numMatches].matchID = std::stoul(localstr);//unsigned
					std::getline(file, localstr, ',');

					m_Match[numMatches].winner = localstr;
					std::getline(file, localstr);

					m_Match[numMatches].loser = localstr;
					numMatches++;
				}
			
			}
			file.close();
		}

	}

	TennisLog::TennisLog(const TennisLog& src)
	{
		if (src) {
			*this = src;
		}
	}
	TennisLog& TennisLog::operator=(const TennisLog& src)
	{
		if (this != &src) {
			delete[] m_Match;
			m_Match = new TennisMatch[numMatches];
			numMatches = src.numMatches;
			for (size_t i = 0; i < numMatches; i++) {
				m_Match[i] = src.m_Match[i];
			}
		}
		return *this;
	}
	TennisLog::~TennisLog() {
		delete[] m_Match;
		m_Match = nullptr;
	}
	void TennisLog::addMatch(const TennisMatch& match)
	{
		TennisMatch* localmatch = new TennisMatch[numMatches + 1];
		for (size_t i = 0; i < numMatches; i++) {
			localmatch[i] = m_Match[i];
		}
		delete[] m_Match;
		m_Match = localmatch;
		m_Match[numMatches] = match;
		numMatches++;
	}
	TennisLog TennisLog::findMatches(const char* name)
	{
		TennisLog locallog;
		for (size_t i = 0; i < numMatches; i++) {
			if (strcmp (name, m_Match[i].winner.c_str()) == 0 || strcmp (name, m_Match[i].loser.c_str()) == 0) {
				//c_str from WS01: converts string back to c-string
				locallog.addMatch(m_Match[i]);
			}
		}
		return locallog;
	}
	const TennisMatch TennisLog::operator[](size_t index) const
	{
		TennisMatch localmatch;
		if (numMatches > index) {
			localmatch = m_Match[index];
		}
		return localmatch;
	}
	TennisLog::operator size_t() const
	{
		return numMatches;
	}
	TennisMatch::operator bool() const
	{
		//return tourneyID.length() != 0;
		return tourneyID.length() != 0 && matchID != 0;
	}

}