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
			ostr.width(23);//changed to 23 for proper display
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
			ostr.fill(' ');//to "unset" fill dots for Timer module's display
		}
		else {
			ostr << "Empty Match";
		}
		return ostr;
	}

	TennisLog::TennisLog() {}

	TennisLog::TennisLog(const char* filename)
	{
		std::ifstream file(filename);
		size_t numLines = 0;
		std::string localstr{};

		if (file) {
			std::getline(file, localstr);//takes line 1

			while (file) {//takes every line from line 2
				std::getline(file, localstr);
				numLines++;//read total number of lines
			}
			m_Match = new TennisMatch[numLines];

			file.clear();
			file.seekg(0);

			std::getline(file, localstr);
			//read the file again for matches
			while (std::getline(file, localstr, ',')) {
				//while file reading is ok
				if (file) {
					//every line of input below
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
			numMatches = src.numMatches;
			m_Match = new TennisMatch[numMatches];
			for (size_t i = 0; i < numMatches; i++) {
				m_Match[i] = src.m_Match[i];
			}
		}
		return *this;
	}
	TennisLog::TennisLog(TennisLog&& src)
	{
		*this = std::move(src);

	}
	TennisLog& TennisLog::operator=(TennisLog&& src)
	{
		if (this != &src) {
			delete[] m_Match;
			m_Match = src.m_Match;
			src.m_Match = nullptr;

			numMatches = src.numMatches;
			src.numMatches = 0;
		}
		return* this;
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
		TennisLog locallog;//local struct
		for (size_t i = 0; i < numMatches; i++) {
			if (strcmp (name, m_Match[i].winner.c_str()) == 0 || strcmp (name, m_Match[i].loser.c_str()) == 0) {
				//c_str from WS01: converts string back to c-string
				locallog.addMatch(m_Match[i]);
			}
		}
		return locallog;
	}
	TennisMatch TennisLog::operator[](size_t index) const
	{
		TennisMatch localmatch;//struct, so return the entire struct, not struct ref!
		if (numMatches > 0) {
			localmatch = m_Match[index];
		}
		else {
			localmatch = {};
		}
		return localmatch;
	}
	TennisLog::operator size_t() const
	{
		return numMatches;
	}
	TennisMatch::operator bool() const
	{
		return tourneyID.length() != 0 || matchID != 0;
	}



}