
// System Include Files //

#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>


//Own include files //
#include "CWaypoint.h"

#include "CPOI.h"


using namespace std;
//CWaypoint::~CWaypoint() {
	// TODO Auto-generated destructor stub
//}

CWaypoint::CWaypoint(string name, double latitude, double longitude)
{
    m_name = name;
	m_latitude = latitude;
    m_longitude = longitude;

#ifdef SHOWADDRESS
    cout << "Address of my object: " << this << endl;
    cout << "Address of m_latitude: " << &m_latitude << endl;
    cout << "Address of m_longitude: " << &m_longitude << endl;
#endif
}

void CWaypoint::set(string name,double latitude, double longitude)
{

if ((latitude >= -90 && latitude <= 90)&&(longitude <=180 && longitude >=-180))
{
   cout << "Value at latitude is " << m_latitude << endl;
   cout << "Value at longitude is " << m_longitude << endl;
}
 else

	cout << "Invalid parameter " << endl;
	m_latitude = 0;
	m_longitude = 0;
}

void CWaypoint::print(int format)  // Printing the latitude and longitude in different formats //
{
    int deg1; int mm1; double ss1;
    int deg2; int mm2; double ss2;

    //transformLongitude2degmmss(deg1,mm1,ss1);  // Defining the transformation functions in print function //
	//transformLatitude2degmmss(deg2,mm2,ss2);

	switch(format)
{
		case 1:
        cout << getName()<<" on latitude = " << m_latitude << " and longitude = " << m_longitude << endl;
        //cout << "Value of Latitude in decimal format "  << m_latitude << endl;
        //cout << "Value of Longitude in decimal format "  <<  m_longitude << endl;

        break;

		case 2:

		transformLongitude2degmmss(deg1,mm1,ss1);  // Defining the transformation functions in print function //
		transformLatitude2degmmss(deg2,mm2,ss2);
		//cout << "Berlin on latitude = " << m_latitude << " and longitude = " << m_longitude << endl;
		cout << getName() <<" on latitude = " <<deg2<<"deg "<<mm2<<"min "<<ss2<<"s " << " and longitude = " <<deg1<<"deg "
				<<mm1<<"min "<<ss1<<"s "<< endl;
	    //cout << "Value of Latitude in (deg,mm,ss) format "  << m_latitude << endl;
	    //cout << "Value of Longitude in (deg,mm,ss) format "  << m_longitude << endl;
        break;
}

}

void CWaypoint::transformLongitude2degmmss(int &deg, int &mm, double &ss)
{

	deg = (int)(getLongitude());
	mm = (int)((getLongitude()-deg)*60);
	ss = (((getLongitude()-deg)*60)-((int)((getLongitude()-deg)*60)))*60;
	//ss = (m_longitude - deg - mm/60)* 3600;
    //cout << "Berlin on Longitude " << m_longitude << endl;


}
void CWaypoint::transformLatitude2degmmss(int &deg, int &mm, double &ss)
{
   deg = (int)(getLatitude());
   mm = (int)((getLatitude()-deg)*60);
   ss = (((getLatitude()-deg)*60)-((int)((getLatitude()-deg)*60)))*60;
   //ss = (m_latitude - deg - mm/60)* 3600;
   //cout << "Berlin on Latitude " << m_latitude << endl;

}
string CWaypoint::getName()   const
{
return m_name;
}
double CWaypoint::getLatitude()
{
return m_latitude;

}
double CWaypoint::getLongitude()
{
return m_longitude;
}
void CWaypoint::getAllDataByReference(string &name,double &latitude, double &longitude)
{
	name = getName();
	latitude = getLatitude();
	longitude = getLongitude();
#ifdef SHOWADDRESS      // To turn off the function implementation(specific block) //
	cout << "Address of my object: " << this << endl;
	cout << "Address of m_latitude: " << &m_latitude << endl;
	cout << "Address of m_longitude: " << &m_longitude << endl;
#endif
// local variables defining //
}

double CWaypoint::calculateDistance(const CWaypoint &wp)
{
  double distance =0;

  distance = R*acos(sin(m_latitude*(PI/180))*sin(wp.m_latitude*(PI/180)) + cos(m_latitude*(PI/180))*cos(wp.m_latitude*(PI/180)) * cos(wp.m_longitude*(PI/180)-m_longitude*(PI/180)));

return distance;
}

// Operator overloading (Task 'i')
ostream & operator <<(ostream &out, const CWaypoint &wp)
{

	void print(int format);
	return out;

}




