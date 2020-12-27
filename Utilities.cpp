// Name: Mia Le
// Seneca Student ID: 131101198
// Seneca email: tknle1@myseneca.ca
// Date of completion: Nov 22, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include "Utilities.h"

using namespace std;
char Utilities::m_delimiter{ ' ' };

void Utilities::setFieldWidth(size_t newWidth) {
	m_widthField = newWidth;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

//Updated this for milestone 3
string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {

	size_t first_pos = next_pos;
	string temp = "";

	next_pos = str.find(m_delimiter, first_pos);

	if (next_pos == string::npos) {
		temp = str.substr(first_pos);
		m_widthField = max(temp.length(), m_widthField);
		more = false;
	}
	else if (first_pos == next_pos)
	{
		more = false;
		throw "No token between delimiters!";
	}
	else {
		temp = str.substr(first_pos, next_pos - first_pos);
		m_widthField = max(temp.length(), m_widthField);
		more = true;
	}
	next_pos++;
	return temp;

}

void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

char Utilities::getDelimiter() {
	return m_delimiter;
}