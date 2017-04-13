/*
 * PoliceReport.h
 *
 *  Created on: Jan 31, 2017
 *      Author: karln
 */

#ifndef POLICEREPORT_H_
#define POLICEREPORT_H_

class PoliceReport {
	long incidentNum_;
	std::string category_;
	std::string description_;
	int day_;
	std::string dateString_;
	std::string district_;
	std::string resolution_;
	std::string address_;

public:
	PoliceReport(
			long incidentNum,
			std::string const &category,
			std::string const &description,
			int day,
			std::string const &dateString,
			std::string const &district,
			std::string const &resolution,
			std::string const &address);
	PoliceReport( long incidentNum ): incidentNum_(incidentNum), day_(0) {}

	virtual ~PoliceReport();
	bool operator< (const PoliceReport& e) const { return (incidentNum_<e.incidentNum_); }
	bool operator== (const PoliceReport& e) const { return (incidentNum_==e.incidentNum_); }
	long getIncidentNumber() {  return incidentNum_; }
    friend std::ostream &operator<<(std::ostream& os, const PoliceReport &rep) {
	    return os << rep.incidentNum_ << '\t' << rep.dateString_ << std::endl
	    		<< rep.category_ << '\t' << rep.description_ << '\t' << rep.resolution_ << std::endl
	    		<< rep.district_ << '\t' << rep.address_ ;
	}
};

#endif /* POLICEREPORT_H_ */

