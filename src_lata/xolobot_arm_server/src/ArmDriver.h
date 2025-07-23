/*
 * ArmDriver.h
 *
 *  Created on: Sept. 16, 2021
 *      Author: antonio
 */

#ifndef SRC_ARMDRIVER_H_
#define SRC_ARMDRIVER_H_

#include <vector>

using namespace std;


class ArmDriver {
public:
	ArmDriver();
	virtual ~ArmDriver();

	virtual void nextArmMove(vector<double> const & inputs, vector<double>& reaction) = 0;
    virtual void setParameters(const char *iName);
};

#endif /* SRC_ARMDRIVER_H_ */
