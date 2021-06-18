
//System Include Files
#include<iostream>
#include<string>

//Own Include Files (Navigation System's major components, GPS sensor, Route and a Point of Interest Database)//

#include "CNavigationSystem.h"
#include "CRoute.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CGPSSensor.h"
#include "CWaypoint.h"
using namespace std;

//Method Implementations

//// Member initializer list(Defining number of Waypoints and POIs)  //
//
CNavigationSystem::CNavigationSystem()
{
}
//
//// Entering POIs and waypoints to the route (STEP4)//
void CNavigationSystem::enterRoute(){

// Implemeting the waypoints and POIS //
CWaypoint WP_Amsterdam("Amsterdam ",52.3142,4.9418);
CWaypoint WP_Wohnung("Nieder-Ramstadter ", 49.859041, 8.674468);
CWaypoint WP_University("Hochschule Darmsatdt ", 49.864740, 8.643225);

m_WpDatabase.addWaypoint(WP_Amsterdam);
m_WpDatabase.addWaypoint(WP_Wohnung);
m_WpDatabase.addWaypoint(WP_University);

m_route.connectToWpDatabase(&m_WpDatabase);
m_route.addWaypoint("Amsterdam");
m_route.addWaypoint("Nieder-Ramstadter");
m_route.addWaypoint("Hochschule Darmsatdt");

CPOI KFC(RESTAURANT,"KFC","Best place to eat and drink ",52.3000,4.9500);
CPOI Tower(SIGHTSEEING,"Luisenplatz","Roman architecture ",52.3800,5.9500);
CPOI Hotel(RESTAURANT,"Ramada","Food with deliciousness ",50.3000,7.9500);

m_PoiDatabase.addPoi(KFC);
m_PoiDatabase.addPoi(Tower);
m_PoiDatabase.addPoi(Hotel);

m_route.connectToPoiDatabase(&m_PoiDatabase);
m_route.addPoi("KFC","Amsterdam");
m_route.addPoi("Luisenplatz","Nieder-Ramstadter");
m_route.addPoi("Ramada","Hochschule Darmsatdt");
}
//
//// Printing POIs and waypoints to the route (STEP5)//
void CNavigationSystem::printRoute(){

	m_route.print();

}
//
//// Getting the current position from the GPS sensor and search for the closest Point of Interest (STEP6)//
//void CNavigationSystem::printDistanceCurPosNextPoi()
//{
//
//CPOI poi;
//double Distance;
//CWaypoint presentlocation;
//
//cout << "Testing of the GPS Sensor and calculating the distance to the next point of interest " << endl;
//presentlocation= m_GPSSensor.getCurrentPosition();
//
//
//Distance = m_route.getDistanceNextPoi(presentlocation,poi);
//
//cout << "Distance to the next point of interset = " << Distance << endl;
////cout << "Point of Interest " << endl;
////cout << "=================="  << endl;
//
//poi.print();
//
//}
//
////IMPLEMENTING THE CHECKING OPERATION OF NAVIGATION SYSTEM //

void CNavigationSystem::run()
{

enterRoute();
printRoute();


}

//
