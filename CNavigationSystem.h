

#ifndef CNAVIGATIONSYSTEM_H
#define CNAVIGATIONSYSTEM_H
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CPOI.h"
#include "CWaypoint.h"


class CNavigationSystem {
private:
	// Solution "c": The reason behind the declaration of private variables in this class is that since navigation system is secured and
	// all the main core components are defined in this class so that's why we have to make it private function and to avoid mismatching
	// with other classes//

    /**
     * @link aggregationByValue 
     */
    CGPSSensor m_GPSSensor;
    /**
     * @link aggregationByValue 
     */
    CRoute m_route;
    /**
     * @link aggregationByValue 
     */
    CPoiDatabase m_PoiDatabase;

    CWpDatabase m_WpDatabase;

public:

    CNavigationSystem();
    void run();

private:

    void enterRoute();
    void printRoute();
    //void printDistanceCurPosNextPoi();
};
/********************
**  CLASS END
*********************/
#endif /* CNAVIGATIONSYSTEM_H */
