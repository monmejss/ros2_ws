/*
 * NeuroControllerDriver.cpp
 *
 *  Created on: Apr 14, 2020
 *      Author: antonio
 */

#include <random>
#include "SimpleArmDriver.h"

using namespace std;

SimpleArmDriver::SimpleArmDriver(int nIn, int nOut, vector<pair<double,double> > &oRanges)
{
    jointValues.assign(nOut, 0.0);
    directions.assign(nOut, 1);
    oBounds = oRanges;
    generator.seed(time(nullptr));
}

SimpleArmDriver::~SimpleArmDriver() {
}

void SimpleArmDriver::nextArmMove(vector<double> const &inputs, vector<double> &reaction){
    uniform_real_distribution<double> distribution(0.05, 0.2);
    uniform_real_distribution<double> direction(0.0, 1.0);

    for (int i = 0; i < reaction.size(); i++)
    {
        if (direction(generator) < 0.1)
            directions[i] = -1*directions[i];

        double delta = directions[i] * distribution(generator);
        reaction[i] = jointValues[i] + delta;

        //if (i == 2) {
        //    cout << "\nDelta= " << delta << endl;
            //cout << "\nInf = " << oBounds[i].first << ", Sup= " << oBounds[i].second << endl;
       // }

        if (reaction[i] > oBounds[i].second) {
            directions[i] = -1*directions[i];
            reaction[i] = oBounds[i].second;
        }
        else if (reaction[i] < oBounds[i].first) {
            directions[i] = -1*directions[i];
            reaction[i] = oBounds[i].first;
        }

        jointValues[i] = reaction[i];
    }
}

