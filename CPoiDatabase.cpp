//System Include Files
#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>

//Own Include Files
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"

using namespace std;

//Method Implementations

//-------------Testing of the class CPoiDatabase//

CPoiDatabase::CPoiDatabase() {


}

void CPoiDatabase::addPoi(CPOI const &poi)
{
   // For adding POI's we have to use insert function
	mymapPoi.insert(pair<string,CPOI>(poi.getName(),poi));  // We have to make getName function "const" in CWaypoint class
	map<string, CPOI> :: iterator i;
for(i=mymapPoi.begin();i!=mymapPoi.end(); i++)
{
	cout << "Name of POI is " << (i->first) << endl;
	cout << "Latitude of POI is " << (i->second).getLatitude() << "and Longitude is " << (i->second).getLongitude() << endl;

}

}

// ----------------------Task 'a'
CPOI* CPoiDatabase::getPointerToPoi(string name)
{
  // declaring local CPOI pointer
  CPOI* ptrpoi;
 std::map<string, CPOI> ::iterator it;
 for(it=mymapPoi.begin();it!=mymapPoi.end(); ++it)
 {
	 if(name==(*it).first)
	 {
		 ptrpoi = &(it->second);
		 return ptrpoi;
	 }

 }

   return 0;
}
// These functions will be used in CSV read/write data operations

map<string, CPOI> CPoiDatabase::getMap()
{
	return mymapPoi;
}

void CPoiDatabase::clearmap()
{
	mymapPoi.clear();
}



