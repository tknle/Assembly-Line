// Name: Mia Le
// Seneca Student ID: 131101198
// Seneca email: tknle1@myseneca.ca
// Date of completion: Nov 22, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>

class Utilities {
	size_t m_widthField{ 1 };
	static char m_delimiter;
public:
	Utilities() {};
	void setFieldWidth(size_t newWidth);
	size_t getFieldWidth() const;
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(char newDelimiter);
	static char getDelimiter();
};


#endif