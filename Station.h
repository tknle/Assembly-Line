// Name: Mia Le
// Seneca Student ID: 131101198
// Seneca email: tknle1@myseneca.ca
// Date of completion: Nov 22, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

class Station {
	int m_id{ 0 };
	std::string m_name{ "" };
	std::string m_desc{ "" };
	int m_nextSerial{ 0 };
	int m_current{ 0 };
	//static data
	static size_t m_widthField;
	static int id_generator;
public:
	Station() {};
	Station(const std::string&);
	const std::string& getItemName() const;
	unsigned int getNextSerialNumber();
	unsigned int getQuantity() const;
	void updateQuantity();
	void display(std::ostream& , bool ) const;


};

#endif