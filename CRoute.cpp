//System include files//
#include <iostream>
#include <string>
#include <list>
#include <cmath>

//Own include files//
#include "CRoute.h"
#include "CWaypoint.h"
#include "CPoiDatabase.h"
#include "CPOI.h"

using namespace std;

CRoute::CRoute()
{
	m_pPoiDatabase = NULL;
	m_pWpDatabase = NULL;
	m_noPois =0;
	m_noWps = 0;

}

CRoute::CRoute(const CRoute &origin)        // COPY CONSTRUCTOR
{
	cout << "Calling the copy constructor from objects at address of " << &origin << "to " << this << endl;

	//Copy the normal attributes

m_pWpDatabase = (origin).m_pWpDatabase;
m_pPoiDatabase= (origin).m_pPoiDatabase;
mylist = (origin).mylist;
m_noPois = (origin).m_noPois;
m_noWps = (origin).m_noWps;

list<CWaypoint*>::const_iterator itr;
for(origin.mylist.begin(); itr!=origin.mylist.end(); itr++)
{
   mylist.push_back(new CWaypoint(*(*itr)));
}
}
// Task 'g'

CRoute & CRoute::operator =(const CRoute &Myroute)     // Assignment operator
{
 if(this != &Myroute)
 {
	 return *this;
	 m_pWpDatabase = (Myroute.m_pWpDatabase);
	 m_pPoiDatabase = (Myroute.m_pPoiDatabase);
	 list<CWaypoint*>::const_iterator itr;
	 for(Myroute.mylist.begin(); itr!=Myroute.mylist.end(); itr++)
	 {
		 mylist.push_back(new CWaypoint(*(*itr)));
         return *this;
	 }

 }
 else cout <<"Matching assignment" << endl;
 return *this;
}

// Task 'f'
void CRoute::addWaypoint(string name)


// Checking of database with route

{
if(m_pWpDatabase->getPointerToWaypoint(name)!= NULL)
{
	CWaypoint *wp = m_pWpDatabase->getPointerToWaypoint(name);
	mylist.push_back(wp);
	cout << "Waypoints added into the route " <<endl;
	cout << wp->getName() << endl;

}

else {
	cerr << "Cannot add more waypoints into the route" << endl;
	}

}
// Task 'f'
void CRoute::addPoi(string namePoi, string afterWp) {
//calling getpointertopoi function //
if((m_pPoiDatabase->getPointerToPoi(namePoi)!= NULL) && (m_pWpDatabase->getPointerToWaypoint(afterWp)!= NULL))
{
	 list<CWaypoint*>:: iterator itr;
     for(itr=mylist.begin();itr!=mylist.end();++itr)
     {
    	 if((*itr)->getName()== m_pWpDatabase->getPointerToWaypoint(afterWp)->getName())
    	 {
    		 cout <<"POI will be added into the route " << endl;
    		 // itr points to afterWp, and then we have to insert poi
             mylist.insert(++itr,m_pPoiDatabase->getPointerToPoi(namePoi));
    	 }
    	 else {
    		 cerr << "ERROR!!! POI cannot be added "<< endl;
    	 }
     }
}

else {
	cerr << "ERROR!!! No connection between the Route and databases "  << endl;
}
}

// This function will tell the distance between nearest possible point of interest //

double CRoute::getDistanceNextPoi(CWaypoint const& wp, CPOI& poi) {




	return 0;



}
// -------------Task 'j'
void CRoute::print()
{
 list<CWaypoint*>::iterator it;

for(it=mylist.begin();it!=mylist.end();++it)
{
	(*it)->print(2);
    cout << (**it) <<endl;
    //Using dynamic casting (to detect the object(Wp or Poi))
    CPOI *tempPoi = dynamic_cast<CPOI*>(*it);

    if(tempPoi!=NULL)
    {
    	cout << tempPoi << endl;
    }
    else
    	{cout << (**it) << endl;}

}
}

CRoute::~CRoute() {

}

void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {
m_pPoiDatabase = pPoiDB;
}

void CRoute::connectToWpDatabase(CWpDatabase* pWpDB) {
m_pWpDatabase = pWpDB;
}

// Operator Overloading (TASK - K)

void CRoute::operator +=(string name){

	{
		if(m_pWpDatabase==NULL)
		{
			cout << "Connection to Wpdatabase has not been done " << endl;
		}
		else{
			if(m_pWpDatabase->getPointerToWaypoint(name)!=NULL)
			{
				addWaypoint(name);

			}
			else
				cout << "The waypoint is invalid and cannot be added " << endl;
		}
	}
	{
		if(m_pPoiDatabase==NULL)
		{
			cout << "Connection to Poidatabase has not been done " << endl;
		}
		else{
			if(m_pPoiDatabase->getPointerToPoi(name)!=NULL)
			{
				mylist.push_back(m_pPoiDatabase->getPointerToPoi(name));
			}
			else
				cout <<"The POI is invalid and cannot be added" << endl;
		}
	}

}

// Operator Overloading (TASK - L)
// IMPORTANT
// Adding two routes by concatenation using "merge" syntax
CRoute CRoute::operator +(CRoute &Rop)
{
mylist.merge(Rop.mylist);
if(m_pPoiDatabase==Rop.m_pPoiDatabase && m_pWpDatabase==Rop.m_pWpDatabase)
{
	mylist.merge(Rop.mylist);
	return *this;
}

else
{
	cout << "ERROR!!! concatenation of 2 routes cannot be done" << endl;
	return Rop;
}

}
