// Name: Mia Le
// Seneca Student ID: 131101198
// Seneca email: tknle1@myseneca.ca
// Date of completion: Nov 22, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "Station.h"

using namespace std;
size_t Station::m_widthField = 0;
int Station::id_generator = 1;

Station::Station(const std::string& str) {
	bool more = true;
	m_id = id_generator;
	Utilities utility;
	size_t next_pos = 0;

	try {
		m_name = utility.extractToken(str, next_pos, more);
		m_nextSerial = stoi(utility.extractToken(str, next_pos, more));
		m_current = stoi(utility.extractToken(str, next_pos, more));
		m_widthField = max(utility.getFieldWidth(), m_widthField);
		m_desc = utility.extractToken(str, next_pos, more);
	}
	catch (string& err) {
		cout << err;
	}

	id_generator++;

}

const std::string& Station::getItemName() const {
	return m_name;
}

unsigned int Station::getNextSerialNumber() {
	m_nextSerial++;
	return m_nextSerial - 1;
}

unsigned int Station::getQuantity() const {
	return m_current;
}

void Station::updateQuantity() {
	getQuantity() > 0 ? m_current-- : 0;
}

void Station::display(ostream& os, bool isFull) const {
	ios io(NULL);
	io.copyfmt(cout);

	os << right << "[" << setw(3) << setfill('0') << m_id << "]" << left;
	os << " Item: " << setw(m_widthField) << setfill(' ') << m_name << right;
	os << " [" << setw(6) << setfill('0') << m_nextSerial << "]" << left;

	if (isFull) {
		os << " Quantity: " << setw(m_widthField) << setfill(' ') << m_current;
		os << " Description: ";
		os.copyfmt(io);
		os << m_desc << endl;
	}
	else {
		os << endl;
	}
}
