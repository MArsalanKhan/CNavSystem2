/*
 * CWpDatabase.h
 *
 *  Created on: Aug 3, 2016
 *      Author: Arsalan Khan
 */

#ifndef CWPDATABASE_H_
#define CWPDATABASE_H_
#include "CWaypoint.h"
#include <map>

// Task 'c'------Creating new class 'CWpDatabase'

class CWpDatabase {

private:

	// Declaring map container

   map <string, CWaypoint> mymapWp;

public:
	CWpDatabase();
	void addWaypoint(CWaypoint const &wp);
	CWaypoint* getPointerToWaypoint(string name);
	void print();     //We have to make virtual function of base class
	map<string,CWaypoint> getMap();
    void clearmap();


};

#endif /* CWPDATABASE_H_ */
