
//System include files//
#include <iostream>
#include <string>

//Own include files //
#include "CPOI.h"
#include "CWaypoint.h"
using namespace std;

CPOI::CPOI(t_poi type, string name, string description, double latitude, double longitude)
{
   // TODO Auto-generated constructor stub
    m_name=name;
	m_description=description;
	m_latitude = latitude;
	m_longitude = longitude;
	m_type=type;

}
void CPOI::getAllDataByReference(string &name, double &latitude, double &longitude, t_poi &type, string &description)
{
	    name=m_name;
	    latitude=m_latitude;
	    longitude=m_longitude;
	    type=m_type;
	    description=m_description;

}

void CPOI::print(){

	cout << "POINT OF INTEREST " << endl;
    cout << "================= "  << endl;


	switch(m_type)
		{

		case RESTAURANT:
			    cout << " of type Restaurant: " << m_description << endl;
			    CWaypoint::print(MMSS);
			    break;

	    case SIGHTSEEING:
	    	cout << " of type sightseeing: " << m_description << endl;
	    	CWaypoint::print(MMSS);
	    	break;
		}


}

// Operator overloading (Task 'i')
ostream & operator <<(ostream &out, const CPOI &poi)
{

	void print(int format);
	return out;

}
