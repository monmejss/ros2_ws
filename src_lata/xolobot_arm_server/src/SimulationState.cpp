
#include "SimulationState.h"

SimulationState::SimulationState(double energy) {
   initialEnergy = energy;
   resetState();
}


void SimulationState::resetState() {
   finishTime = 1000.0;
   currentTime = 0.0;
   currentPosition = 0.0;
   position[0] = 0;
   position[1] = 0;
   robotEnergy = initialEnergy;
   robotDamage = 0.0;
   hasTimeRunOut = false;
}
