/*
 * CPersistentStorage.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: Arsalan Khan
 */

#include "CPersistentStorage.h"
#include "CWpDatabase.h"
#include "CPoiDatabase.h"

// System include files.
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <ostream>
#include <sstream>   // String stream, (convert int value into string value)
#include <fstream>   // File Handling


//enum MergeMode { MERGE, REPLACE };

using namespace std;


//CPersistentStorage::CPersistentStorage()
//{
//	// TODO Auto-generated constructor stub
//
//}

//
//void CPersistentStorage::setMediaName(string name) {
//
//
//}
//
//bool writeData (const CWpDatabase& waypointDb, const CPoiDatabase& poiDb) {
//
//
//return true;
//}
//
//bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode) {
//	// reading a text file
//
////	cout << "Reading of data from storage file " << endl;
////
////// string stream. search
////	string num = "44";
////   stringstream sso;
////   sso << num;
////   int input;
////   sso >> input;
////   cout << input+2 << endl;
////   cout << num+"2"<< endl;
//
////	switch(MergeMode)
////			{
////              case MERGE:
////
////				    break;
////
////		    case REPLACE:
////
////		    	break;
////			}
//
////string line;
//////	  ifstream myfile ("csv-wp.txt");
//////	  if (myfile.is_open())
//////	  {
//////	    while ( getline (myfile,line) )
//////	    {
//////	      cout << line << '\n';
//////	    }
//////	    myfile.close();
//////	  }
//////
//////	  else cout << "Unable to open file";
//////
//////	  return 0;
////
////	ifstream myReadFile;
////	myReadFile.open("csv-wp.txt");
////
////	if (myReadFile.is_open()) {
////	    while (!myReadFile.eof()) // To get you all the lines.
////	    {
////	    	getline(myReadFile,line);   // Saves the line in STRING.
////            cout << line;     // Prints our String.
////	    }
////
////	myReadFile.close();
////	//return 0;
////}
//	return true;
//}
//
////CPersistentStorage::~CPersistentStorage()
////{
////	// TODO Auto-generated destructor stub
////}
//
