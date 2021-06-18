/*
 * CDerived.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: Arsalan Khan
 */
// Own include files
#include "CDerived.h"
#include "CPersistentStorage.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"

// System include files
#include <map>
#include <list>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;


void CDerived::setMediaName(string name)
{

	m_WpFileName = name + "-wp.txt";
	m_PoiFileName = name + "-poi.txt";
}

bool CDerived::writeData(const CWpDatabase &waypointDb, const CPoiDatabase &poiDb)
{
	//Write operation for Waypoint Database
		CWpDatabase temp_wpDb1;
		temp_wpDb1 = waypointDb;

		// Declaring local map for Waypoints
		map<string, CWaypoint> temp_mapWpDb;
		map<string, CWaypoint>::iterator itr;        // Iterator for Waypoint

		// We have to get access of Waypoint map
		temp_mapWpDb = temp_wpDb1.getMap();

		ofstream myfilewp;

		myfilewp.open(m_WpFileName.c_str());
		if (myfilewp.is_open())
		{
			cout << "A file is getting created for the Waypoint Database" << endl;
			for (itr = temp_mapWpDb.begin(); itr != temp_mapWpDb.end();
					itr++)
			{
				myfilewp << itr->first << ";" << ((itr->second).getLatitude())
						<< ";" << ((itr->second).getLongitude()) << endl;
			}
			myfilewp.close();
		}
		else
			cout << "Unable to open the file" << endl;

		//Write operation for POI Database
		map<string, CPOI> temp_mapPoiDb;
		map<string, CPOI>::iterator it;         // Iterator for POI

		CPoiDatabase temp_poiDb;
		temp_poiDb = poiDb;

		// We have to get access of POI map
		temp_mapPoiDb = temp_poiDb.getMap();

		ofstream myfilePoi;
		myfilePoi.open(m_PoiFileName.c_str());

		if (myfilePoi.is_open())
		{
			cout << "A file is getting created for the POI Database" << endl;
			string poi_name, poi_description, poi_typeString;
			double poi_latitude, poi_longitude;
			t_poi poi_type;
			for (it = temp_mapPoiDb.begin();
					it != temp_mapPoiDb.end(); it++)
			{
				(it->second).getAllDataByReference(poi_name, poi_latitude,
						poi_longitude, poi_type, poi_description);

				//POI type is in the order: RESTAURANT,SIGHTSEEING,THEATER,OTHER
				switch (poi_type)
				{
				case 0:
					poi_typeString = "RESTAURANT";
					break;

				case 1:
					poi_typeString = "SIGHTSEEING";
					break;

				}
				myfilePoi << poi_typeString << ";" << it->first << ";"
						<< poi_description << ";"
						<< ((it->second).getLatitude()) << ";"
						<< ((it->second).getLongitude()) << endl;
			}
			myfilePoi.close();
		}
		else
			cout << "Unable to open the file" << endl;

		return true;

}


bool CDerived::readData(CWpDatabase &waypointDb, CPoiDatabase &poiDb, MergeMode mode)
{
	switch (mode)
		{
		case REPLACE:
			waypointDb.clearmap();
			poiDb.clearmap();
			break;

		case MERGE:
			break;

		}

		//Read operation for Waypoint Database
		string wp_line, wp_token;
		string temp_wpName, temp_wplatStr1, temp_wplatStr2, temp_wplonStr1,
				temp_wplonStr2;
		double temp_wpLatitude = 0, temp_wpLongitude = 0;

		ifstream myFileWp;
		myFileWp.open(m_WpFileName.c_str());

		if (myFileWp.is_open() && (!myFileWp.eof()))
		{
			int count_Wps = 1;
			while (getline(myFileWp, wp_line))
			{
				istringstream wp_split(wp_line);
				int no_wpValues = 0;
				stringstream temp_wpStr[10];
				while (getline(wp_split, wp_token, ';'))
				{
					temp_wpStr[no_wpValues] << wp_token;
					no_wpValues++;
				}
				if (no_wpValues < 3)
				{
					cerr
							<< "ERROR: Too few fields in the Waypoint data file in line "
							<< count_Wps << endl;
				}
				else if (no_wpValues > 3)
				{
					cerr
							<< "ERROR: Too many fields in the Waypoint data file in line "
							<< count_Wps << endl;
				}
				else
				{
					temp_wpStr[0] >> temp_wpName;
					temp_wpStr[1] >> temp_wplatStr1;
					temp_wplatStr2 = temp_wplatStr1;

					int pos_lat = temp_wplatStr1.find(',', 0);
					if (pos_lat < 0)
					{
						temp_wpLatitude = atof(temp_wplatStr2.c_str());
					}
					else
					{
						cerr << "Error: German Notation in line " << count_Wps
								<< " setting latitude as 0" << endl;
						temp_wpLatitude = 0;
					}

					temp_wpStr[2] >> temp_wplonStr1;
					temp_wplonStr2 = temp_wplonStr1;
					int pos_lon = temp_wplonStr1.find(',', 0);
					if (pos_lon < 0)
					{
						temp_wpLongitude = atof(temp_wplonStr2.c_str());
					}
					else
					{
						cerr << "Error: German Notation in line " << count_Wps
								<< " setting longitude as 0" << endl;
						temp_wpLongitude = 0;
					}
					CWaypoint temp_Waypoint(temp_wpName, temp_wpLatitude,
							temp_wpLongitude);
					waypointDb.addWaypoint(temp_Waypoint);
				}
				count_Wps++;
			}
		}

		myFileWp.close();

		//Read operation for POI Database
		string temp_poiName, temp_poiDescription, poi_line, poi_token;
		string temp_poiTypeString,temp_poiLatStr1,temp_poiLatStr2,temp_poiLonStr1,temp_poiLonStr2;
		t_poi temp_poiType;
		double temp_poiLatitude = 0, temp_poiLongitude = 0;

		ifstream myFilePoi;
		myFilePoi.open(m_PoiFileName.c_str());

		if (myFilePoi.is_open() && (!myFilePoi.eof()))
		{
			int count_Pois = 1;
			while (getline(myFilePoi, poi_line))
			{
				istringstream poi_split(poi_line);
				int no_poiValues = 0;
				stringstream temp_poiStr[10];
				while (getline(poi_split, poi_token, ';'))
				{
					temp_poiStr[no_poiValues] << poi_token;
					no_poiValues++;
				}

				if (no_poiValues > 5)
				{
					cerr << "ERROR: Too many fields in the POI data file in line "
							<< count_Pois << endl;
				}
				else if (no_poiValues < 5)
				{
					cerr << "ERROR: Too few fields in the POI data file in line "
							<< count_Pois << endl;
				}
				else
				{
					//Using getline here for strings as it takes whitespaces also
					//In case of stringstream whitespaces are not taken
					getline(temp_poiStr[0], temp_poiTypeString);
					getline(temp_poiStr[1], temp_poiName);
					getline(temp_poiStr[2], temp_poiDescription);

					temp_poiStr[3] >> temp_poiLatStr1;
					temp_poiLatStr2=temp_poiLatStr1;
					int pos_lat = temp_poiLatStr1.find(',', 0);
					if (pos_lat < 0)
					{
						temp_poiLatitude = atof(temp_poiLatStr2.c_str());
					}
					else
					{
						cerr << "Error: German Notation in line " << count_Pois
								<< " setting latitude as 0" << endl;
						temp_poiLatitude = 0;
					}

					temp_poiStr[4] >> temp_poiLonStr1;
					temp_poiLonStr2=temp_poiLonStr1;
					int pos_lon = temp_poiLonStr1.find(',', 0);
					if (pos_lon < 0)
					{
						temp_poiLongitude = atof(temp_poiLonStr2.c_str());
					}
					else
					{
						cerr << "Error: German Notation in line " << count_Pois
								<< " setting longitude as 0" << endl;
						temp_poiLongitude = 0;
					}
					//Checking the type of POI entered in the file
					//The order is RESTAURANT,SIGHTSEEING,THEATER,OTHER in the enum type
					if (temp_poiTypeString == "RESTAURANT")
					{
						temp_poiType = RESTAURANT;
					}
					else if (temp_poiTypeString == "SIGHTSEEING")
					{
						temp_poiType = SIGHTSEEING;
					}

					else
					{
						cerr << "Please enter a valid Type of POI in line "
								<< count_Pois << endl;
						break;
					}
					CPOI temp_poi(temp_poiType, temp_poiName, temp_poiDescription,
							temp_poiLatitude, temp_poiLongitude);
					poiDb.addPoi(temp_poi);
				}
				count_Pois++;
			}

		}

		myFilePoi.close();




	return true;


}



