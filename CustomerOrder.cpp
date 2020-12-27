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
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(const string& str) {
	Utilities utility;
	size_t next_pos = 0;
	bool more = true;
	m_lstItem = nullptr;
	Item* list[1000];

	try {
		m_name = utility.extractToken(str, next_pos, more);
		m_product = utility.extractToken(str, next_pos, more);

		string tempItem;
		while (more) {
			tempItem = utility.extractToken(str, next_pos, more);
			list[m_cntItem] = new Item(tempItem);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];

		for (unsigned int i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = list[i];
		}

		m_widthField = utility.getFieldWidth() > m_widthField ? utility.getFieldWidth() : m_widthField;

	}
	catch (string& msg) {
		cout << msg;
	}

}

CustomerOrder::~CustomerOrder() {
	//without this will cause mem leak! 
	if (m_lstItem == nullptr) {
		return;
	}

	for (unsigned int i = 0; i < m_cntItem; i++) {
		delete m_lstItem[i];
	}

	delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const {
	bool filled = true;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false) {
			filled = false;
		}
	}
	return filled;
}

bool CustomerOrder::isItemFilled(const string& itemName) const {
	bool filled = true;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName.compare(itemName) == 0) {
			filled = m_lstItem[i]->m_isFilled;
		}
	}
	return filled;
}

void CustomerOrder::fillItem(Station& station, ostream& os) {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName.compare(station.getItemName()) == 0) {
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else {
				os << "    Unable to fill NAME, PRODUCT " << m_lstItem[i]->m_itemName << endl;
			}
		}
	}
}

void CustomerOrder::display(ostream& os) const {
	os << m_name << " - " << m_product << endl;

	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << setfill('0') << right << setw(6) << m_lstItem[i]->m_serialNumber << "]" << " ";
		os << setfill(' ') << left << setw(m_widthField) << m_lstItem[i]->m_itemName << " - ";
		os << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << endl;
	}
}