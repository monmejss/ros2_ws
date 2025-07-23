#ifndef SIMULATIONSTATE_H
# define SIMULATIONSTATE_H

class SimulationState {

public:
   SimulationState(double energy = 1000);

   double finishTime;        // Time taken to reach the object.    
   double currentTime;       // Total simulation time.
   double currentPosition;   // Not used by the arm's simulation.
   double position[2];       
   double robotEnergy;
   double initialEnergy;
   double robotDamage;
   bool hasTimeRunOut;      // the time to reach the object has run out?

   void resetState();
};

#endif
