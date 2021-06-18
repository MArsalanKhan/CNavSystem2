#ifndef CROUTE_H_
#define CROUTE_H_
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CPOI.h"

#include <iostream>
#include <string>
#include <list>

class CRoute {

private:

	// ----------Task 'e'
	// Declaring list container
	std::list <CWaypoint*> mylist;
    list <CWaypoint*> :: iterator itr;

    //declaring additional attributes
    CPoiDatabase* m_pPoiDatabase;
    CWpDatabase* m_pWpDatabase;
    int m_noWps;
    int m_noPois;


public:
    CRoute();  // Initial values are given to the constructor //

    CRoute(CRoute const&origin);

    ~CRoute();

    void connectToPoiDatabase(CPoiDatabase* pPoiDB);

    // Solution "b": (The idea behind the method is that we have to connect the point of interest database to CRoute Function and for this we have
    //to declare pointer variable m_pPoiDB in this class so that we can have access to all POIs we have stored in the array block. We can get the value
    // of the respective POI by having pointer address of it. The value for the parameter "pPoiDB" will be provided by CPOI Database in which there are
    // many Point of Interests//

    void connectToWpDatabase(CWpDatabase* pWpDB);


    void addWaypoint(string name);

    void addPoi(string namePoi, string afterWp);

    double getDistanceNextPoi(CWaypoint const& wp, CPOI& poi);

    void print();

    // Operator overloading methods

    CRoute & operator =(const CRoute &Myroute);
    void operator +=(string name);
    CRoute operator +(CRoute &Rop);



};

#endif /* CROUTE_H_ */
