/*
 * ReportProcessor.cpp
 *
 *  Created on: Jan 31, 2017
 *      Author: karln
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#include "PoliceReport.h"

using namespace std;

// functions
vector<PoliceReport> getPoliceReports();
list<PoliceReport> getPoliceReportList();
void halfHelper(int first, int mid, int last, set<PoliceReport> &reportTree, vector<PoliceReport> &policeReports);
void print10RandomReports(vector<PoliceReport> &policeReports, set<PoliceReport> &reportTree);

int main() {

    srand ( unsigned ( std::time(0) ) );

	vector<PoliceReport> policeReports = getPoliceReports();
//	list<PoliceReport> policeReportList = getPoliceReportList();

	set<PoliceReport> reportTree;

	clock_t start = clock();

	random_shuffle(policeReports.begin(), policeReports.end());

	for ( vector<PoliceReport>::iterator it=policeReports.begin(); it!=policeReports.end(); ++it ) {
		reportTree.insert(*it);
	}

/*
	policeReportList.sort();

	vector<PoliceReport> policeReports( policeReportList.begin(), policeReportList.end() );
	policeReportList.clear();

	halfHelper(0, policeReports.size()/2, policeReports.size()-1, 0, reportTree, policeReports );
	reportTree.insert(policeReports.front());
	reportTree.insert(policeReports.back());
*
*/
	cout << "list count: " << policeReports.size() << endl;
	cout << "set count: " << reportTree.size() << endl;

	clock_t end = clock();
	double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;

	cout << "Time was " << time << endl;
	print10RandomReports(policeReports, reportTree);
	return 0;
}

void print10RandomReports(vector<PoliceReport> &policeReports, set<PoliceReport> &reportTree) {
	long indicentNumbers[10];
	for (int i = 0; i < 10; i++) {
		indicentNumbers[i] = policeReports[i].getIncidentNumber();
	}
	sort( policeReports.begin(), policeReports.end() );
	for (int i = 0; i < 10; i++) {
		long incidentNumber = indicentNumbers[i];

		clock_t start = clock();
		set<PoliceReport>::iterator it = reportTree.find(incidentNumber);
		clock_t end = clock();
		double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
		cout << "Time for set find was " << time << endl;
		cout << "Report = " << *it << endl;

		// compare this to iterating through a sorted version of the list
		start = clock();
		vector<PoliceReport>::iterator vit = std::find(policeReports.begin(), policeReports.end(), incidentNumber);
		end = clock();
		time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
		cout << "Time for vector find was " << time << endl;
		cout << "Report = " << *vit << endl;

	}

}

void halfHelper(int first, int mid, int last, set<PoliceReport> &reportTree, vector<PoliceReport> &policeReports) {
	if( (last - first) <= 1 ) return;
	reportTree.insert(policeReports[mid]);
	halfHelper(first, first + (mid-first)/2, mid, reportTree, policeReports);
	halfHelper(mid, mid + (last-mid)/2, last, reportTree, policeReports);
}

vector<PoliceReport> getPoliceReports() {
	string line;
	ifstream myfile("SFPD_Incidents_TheftLarceny.csv");
	int lineCount = 0;
	string temp[8];
	vector<PoliceReport> policeReports;

	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			int i = 0;
			istringstream iss(line);
			while (getline(iss, temp[i], ',')) {
				i++;
			}
			PoliceReport report(atol(temp[0].c_str()), temp[1], temp[2],
					atoi(temp[3].c_str()), temp[4], temp[5], temp[6], temp[7]);
			policeReports.push_back(report);
			lineCount++;
		}
		myfile.close();
	}

	else
		cout << "Unable to open file";

	return policeReports;
}


list<PoliceReport> getPoliceReportList() {
	string line;
	ifstream myfile("SFPD_Incidents_TheftLarceny.csv");
	int lineCount = 0;
	string temp[8];
	list<PoliceReport> policeReports;

	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			int i = 0;
			istringstream iss(line);
			while (getline(iss, temp[i], ',')) {
				i++;
			}
			PoliceReport report(atol(temp[0].c_str()), temp[1], temp[2],
					atoi(temp[3].c_str()), temp[4], temp[5], temp[6], temp[7]);
			policeReports.push_back(report);
			lineCount++;
		}
		myfile.close();
	}

	else
		cout << "Unable to open file";

	return policeReports;
}
