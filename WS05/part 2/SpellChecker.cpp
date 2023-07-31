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
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
		/*receives the address of a C-style null-terminated string that holds the name of the file that contains the misspelled words. If the file exists, this constructor loads its contents. If the file is missing, this constructor throws an exception of type const char*, with the message Bad file name!. Each line in the file has the format BAD_WORD GOOD_WORD; the two fields can be separated by any number of spaces.*/
	{
		std::ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		else {
			for (size_t i = 0; i < max_word && file; i++) {
				file >> m_badWords[i];
				file >> m_goodWords[i];
				//Book and Movie have their own trim already
			}
			file.close();
		}
	}

	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < max_word; i++) {
			while (text.find(m_badWords[i]) != std::string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);

				count[i]++;
			}
		}
		//To find badword in the text to be of the string type
		//string::replace(pos, len, const& str)
		//1. if the bad word is not npos
		//2. start from the bad word, along its length
		//3. replace bad word with good word
		//4. count replacements, as below
	}

	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < max_word; i++) {
			out.width(15);
			out.setf(std::ios::right);
			out << m_badWords[i] << ": " << count[i] << " replacements" << std::endl;//counter here
		}
		//You will have to design a method to remember how many times each bad word has been replaced.
	}

}