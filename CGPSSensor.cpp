//System Include Files

#include <iostream>
#include <string>

//Own Include Files
#include "CGPSSensor.h"
#include "CWaypoint.h"


//Method Implementations

//Getting current position values //

CGPSSensor::CGPSSensor()
{

}
CWaypoint CGPSSensor::getCurrentPosition(){

	//string name;
    double Latitude;
    double Longitude;


    //cout << "Enter the name of the current position " << endl;
    //cin >> name;
    cout << "Enter the latitude of the current position " << endl;
    cin >> Latitude;
    cout << "Enter the longitude of the current position " << endl;
    cin >> Longitude;

    CWaypoint presentlocation("presentlocation",Latitude,Longitude);
    return presentlocation;
}






