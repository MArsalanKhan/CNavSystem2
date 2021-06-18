/*
 * CDerived.h
 *
 *  Created on: Aug 4, 2016
 *      Author: Arsalan Khan
 */

#ifndef CDERIVED_H_
#define CDERIVED_H_
#include "CPersistentStorage.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"

// System include files

#include <map>
#include <list>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>

//Doing inheritance of the abstract class
class CDerived :public CPersistentStorage
{
private:
	string m_WpFileName;
    string m_PoiFileName;

public:
	//CDerived();

	void setMediaName(string name) ;
	 bool writeData (const CWpDatabase& waypointDb, const CPoiDatabase& poiDb) ;
		bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode) ;


  //virtual ~CDerived();
};

#endif /* CDERIVED_H_ */
