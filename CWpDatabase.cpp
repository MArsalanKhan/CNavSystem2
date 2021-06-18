/*
 * CWpDatabase.cpp
 *
 *  Created on: Aug 3, 2016
 *      Author: Arsalan Khan
 */

#include "CWpDatabase.h"
#include "CWaypoint.h"
#include <iostream>
#include <map>
#include <string>


using namespace std;

CWpDatabase::CWpDatabase() {
	// TODO Auto-generated constructor stub

}

void CWpDatabase::addWaypoint(const CWaypoint &wp)
{
  mymapWp.insert(pair<string, CWaypoint>(wp.getName(),wp));
  map<string , CWaypoint>::iterator i;
  for(i=mymapWp.begin();i!=mymapWp.end(); i++)
  {
	  cout << "Name of Waypoint is " << (i->first) << endl;
	  cout << "Latitude is " << (i->second).getLatitude() << " and Longitude is " << (i->second).getLongitude() << endl;
  }
}
CWaypoint* CWpDatabase::getPointerToWaypoint(string name)
{
	CWaypoint* ptrwp;
	map<string , CWaypoint>::iterator it;
	for(it=mymapWp.begin();it!=mymapWp.end(); ++it)
	{
		if(name==(*it).first)
		{
			ptrwp = &(it->second);
			return ptrwp;
		}
	}


	return 0;

}
// These functions will be used in CSV read/write data operations
map<string, CWaypoint> CWpDatabase::getMap()
{
	return mymapWp;
}


void CWpDatabase::clearmap()
{
	mymapWp.clear();
}

