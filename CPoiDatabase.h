/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOIDATABASE.H
* Author          :
* Description     :
*
*
****************************************************************************/
#ifndef CPOIDATABASE_H
#define CPOIDATABASE_H
#include "CPOI.h"


#include <string.h>
#include <iostream>
#include <map>

using namespace std;

class CPoiDatabase {

private:

	// Declaring map container

   map <string, CPOI> mymapPoi;

public:

    CPoiDatabase();

    void addPoi(CPOI const &poi);

    CPOI* getPointerToPoi(string name);

    // For having accessing of map container for read/write data operations
    map<string,CPOI> getMap();


    void clearmap();
};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H */
