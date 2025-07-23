/*
 * SimpleArmDriver.h
 *
 *  Created on: Sept. 16, 2021
 *      Author: antonio
 */

#ifndef SRC_SIMPLEDRIVER_H_
#define SRC_SIMPLEDRIVER_H_

#include "ArmDriver.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

class SimpleArmDriver : public ArmDriver {
public:
	SimpleArmDriver(int nIn, int nOut, vector<pair<double,double> > &oRanges);
	virtual ~SimpleArmDriver();

	virtual void nextArmMove(vector<double> const & inputs, vector<double>& reaction);
    //virtual void setParameters(const char* weightsFile);

private:
    vector<pair<double,double> > oBounds;  // Range for each output value.
    vector<double> jointValues;  // Range for each output value.
    vector<int> directions;
    mt19937 generator;


};

#endif /* SRC_SIMPLEDRIVER_H_ */
