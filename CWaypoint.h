/*
 * CWaypoint.h
 *
 *  Created on: Oct 25, 2015
 *      Author: Arsalan Khan
 */
#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_
#include <string>
#include <iostream>

#define DEGREE 1
#define MMSS 2
//#define SHOWADDRESS
#define PI 3.14159
const double R = 6378;

using namespace std;

class CWaypoint {
public:

	CWaypoint(string name="", double latitude=0, double longitude=0); // Initial values given to the constructor//
	void set(string name,double latitude, double longitude);
	string getName()      const;   // const is Important for getting access of POI's getName.
	double getLatitude();
	double getLongitude();
	void getAllDataByReference(string &name,double &latitude, double &longitude);
	double calculateDistancePlain(const CWaypoint &wp);
	double calculateDistance(const CWaypoint &wp);
	virtual void print(int format);   // We have to make the method of base class "virtual" (LATE-Binding)
	friend ostream &operator <<(ostream &out, const CWaypoint &wp);


private:
    void calculateXYZ(double &x,double &y,double &z);
    void transformLongitude2degmmss(int &deg, int &mm, double &ss);
    void transformLatitude2degmmss(int &deg, int &mm, double &ss);


protected:
	string m_name;
    double m_latitude;
    double m_longitude;

};

#endif /* CWAYPOINT_H_ */
