/*
 * CGPSSensor.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Arsalan Khan
 */

#ifndef MYCODE_CGPSSENSOR_H_
#define MYCODE_CGPSSENSOR_H_

#include "CWaypoint.h"

class CGPSSensor {
public:

    CGPSSensor();

    CWaypoint getCurrentPosition();
};
#endif /* MYCODE_CGPSSENSOR_H_ */
