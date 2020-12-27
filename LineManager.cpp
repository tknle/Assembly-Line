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
#include <fstream>

#include "Utilities.h"
#include "Station.h"
#include "LineManager.h"

LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& v_workstation, std::vector<CustomerOrder>& v_order) {
	
	std::ifstream file(filename);
	if (!file) {
		throw std::string("Unable to open [") + filename + "] file.";
	}
	
	while (!file.eof()){

		std::string rec ="";
		std::string firstStr = "";
		std::string secondStr = "";
		size_t next_pos = 0;
		bool more = true;

		Utilities utility;
		
		Workstation* firstWS;
		Workstation* secondWS;

	
		std::getline(file, rec);
		firstStr = utility.extractToken(rec, next_pos, more);
		if (more) {
			secondStr = utility.extractToken(rec, next_pos, more);
		}
		else {
			secondStr = "";
		}

		firstWS = nullptr;
		secondWS = nullptr;

		for (std::size_t i = 0; i < v_workstation.size(); ++i) {
			if (v_workstation[i]->getItemName().compare(firstStr) == 0) {
				firstWS = v_workstation[i];
			}
			if (secondStr.compare("") != 0 && v_workstation[i]->getItemName().compare(secondStr) == 0) {
				secondWS = v_workstation[i];
			}
		}

		if (secondWS != nullptr) {
			firstWS->setNextStation(*secondWS);
		}

	}

	m_cntCustomerOrder = v_order.size();

	for (std::size_t i = 0; i < v_order.size(); ++i) {
		ToBeFilled.push_back(std::move(v_order[i]));
	}

	for (std::size_t i = 0; i < v_workstation.size(); ++i) {
		AssemblyLine.push_back(v_workstation[i]);
	}

}

bool LineManager::run(std::ostream& os) {
	static size_t count = 1;
	os << "Line Manager Iteration: " << count++ << std::endl;
	int begin = 0;
	CustomerOrder temp;
	bool full = false;

	if (!ToBeFilled.empty()) {	
		for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
			begin = i;
			for (std::size_t j = 0; j < AssemblyLine.size(); ++j) {
				if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0) {
					begin = -1;
				}
			}

			if (begin != -1) {
				break;
			}
		}

		*AssemblyLine[begin] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();

	}

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->runProcess(os);
	}

	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		if (AssemblyLine[i]->getNextStation() == nullptr)
		{		
			if (AssemblyLine[i]->getIfCompleted(temp)) {
				Completed.push_back(std::move(temp));
			}
		}
		else {
			AssemblyLine[i]->moveOrder();
		}
	}

	if (Completed.size() == m_cntCustomerOrder) {
		full = true;
	}
	
	return full;
	
}

void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (std::size_t i = 0; i < Completed.size(); ++i) {
		Completed[i].display(os);
	}
}

void LineManager::displayStations() const {
	for (std::size_t i = 0; i < AssemblyLine.size(); ++i) {
		AssemblyLine[i]->display(std::cout);
	}
}

void LineManager::displayStationsSorted() const {
	int begin = 0;
	for (size_t i = 0; i < AssemblyLine.size(); ++i) {
		begin = i;
		for (size_t j = 0; j < AssemblyLine.size(); ++j) {

			if (AssemblyLine[j]->getNextStation() != nullptr && AssemblyLine[i]->getItemName().compare(AssemblyLine[j]->getNextStation()->getItemName()) == 0) {
				begin = -1;
			}
		}
		if (begin != -1) {
			break;
		}
	}

	const Workstation* wsStart = AssemblyLine[begin];

	while (wsStart != nullptr) {
		wsStart->display(std::cout);
		wsStart = wsStart->getNextStation();
	}
}