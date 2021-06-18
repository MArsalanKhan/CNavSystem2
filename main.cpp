
// System Include Files //
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>

// Own include files //
#include "CWaypoint.h"
#include "CPOI.h"
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"
#include "CNavigationSystem.h"

using namespace std;

int main(){
	string name;
	//double latitude;
	//double longitude;
	string cityname;
	double citylatitude;
	double citylongitude;
	CWaypoint berlin("Berlin", 52.5166, 13.4);
    //berlin.print(1);
	berlin.print(2);

    cout << "==========" << endl;
    CWaypoint amsterdam("Amsterdam", 52.3142, 4.9418);
    //amsterdam.print(1);
	amsterdam.print(2);

	cout << "==========" << endl;
	CWaypoint darmstadt("Darmstadt", 49.8667, 8.6500);
    //darmstadt.print(1);
	darmstadt.print(2);

	cout << "==========" << endl;
	CWaypoint tokyo("Tokyo", 35.6833, 139.6833);
    tokyo.getAllDataByReference(cityname, citylatitude,citylongitude);

#ifdef SHOWADDRESS
    cout << "Address of cityname: " << &cityname << endl;
    cout << "Address of citylatitude: " << &citylatitude << endl;
    cout << "Address of citylongitude: " << &citylongitude << endl;
#endif
	tokyo.print(1);
//	tokyo.print(2);

	cout << "==========" << endl;
    cout << "Distance between Amsterdam and Berlin is " << amsterdam.calculateDistance(berlin) << endl;

    cout << "Distance between Tokyo and Berlin is " <<  tokyo.calculateDistance(berlin) << endl;





//    CWaypoint trackingpoint("trackingpoint",latitude,longitude);
//    CGPSSensor cp;
//    trackingpoint=cp.getCurrentPosition();
//    trackingpoint.getAllDataByReference(name,latitude,longitude);
    //cout << "The present position is at " << name << " with latitude= " << latitude << " and longitude= " <<  longitude << endl;


//   CRoute ca(2,2);
//   ca.addWaypoint(berlin);


    CNavigationSystem navigation;
    navigation.run();

    return 0;
}
