#include "ArmState.h"

ArmState::ArmState() {}

void ArmState::resetState() {
    SimulationState::resetState(); 
       
    distanceToGo = 1000.0;
    minDist2Go = 1000.0;
    distanceTravelled = 0.0;
    handVelocity = 100; // Un valor muy grande.
    objectReached = false;
}