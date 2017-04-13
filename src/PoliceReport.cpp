/*
 * PoliceReport.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: karln
 */

#include <string>
#include <iostream>

#include "PoliceReport.h"

PoliceReport::PoliceReport(
			long incidentNum,
			std::string const &category,
			std::string const &description,
			int day,
			std::string const &dateString,
			std::string const &district,
			std::string const &resolution,
			std::string const &address)
	: incidentNum_(incidentNum),
	  category_(category),
	  description_(description),
	  day_(day),
	  dateString_(dateString),
	  district_(district),
	  resolution_(resolution),
	  address_(address) {
}

PoliceReport::~PoliceReport() {
	// TODO Auto-generated destructor stub
}

