
#ifndef CPOI_H
#define CPOI_H

#include <iostream>
#include <string>
#include "CWaypoint.h"
#define DEGREE 1
#define MMSS 2


using namespace std;


enum t_poi{RESTAURANT,SIGHTSEEING};     //defining enumeration type for Waypoints and POIs//

class CPOI: public CWaypoint
{

private:

	t_poi m_type;
	string m_description;

public:

    void print();

    CPOI(t_poi type=RESTAURANT, string name="ABC", string description="Best place to eat ", double latitude=0, double longitude=0);

    void getAllDataByReference(string &name, double &latitude, double &longitude, t_poi &type, string &description);
    friend ostream &operator <<(ostream &out, const CPOI &poi);
	//CPOI();
	//virtual ~CPOI();
};

#endif /* MYCODE_CPOI_H_ */
