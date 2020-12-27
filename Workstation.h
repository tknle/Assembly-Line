// Name: Mia Le
// Seneca Student ID: 131101198
// Seneca email: tknle1@myseneca.ca
// Date of completion: Nov 22, 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <deque>
#include <string>
#include "Station.h"
#include "CustomerOrder.h"
class Workstation :
	public Station
{
	std::deque<CustomerOrder> m_orders;
	Workstation* m_pNextStation{ nullptr };

public:
	Workstation(const std::string&);	
	void runProcess(std::ostream&);
	bool moveOrder();
	void setNextStation(Workstation& station);
	const Workstation* getNextStation() const;
	bool getIfCompleted(CustomerOrder& order);
	void display(std::ostream&)const;
	Workstation& operator+=(CustomerOrder&&);
	//DELETE copy and move
	Workstation(const Workstation&) = delete;
	Workstation& operator=(const Workstation&) = delete;
	Workstation(Workstation&& ) noexcept = delete;
	Workstation& operator=(Workstation&& ) noexcept = delete;
	
};

#endif


