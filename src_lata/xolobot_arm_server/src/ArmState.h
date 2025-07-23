#ifndef EB366BBB_29C2_46ED_BA60_ED5FA6A69C54
#define EB366BBB_29C2_46ED_BA60_ED5FA6A69C54

#include "SimulationState.h"

class ArmState : public SimulationState {
public:
   ArmState(); 
   void resetState();  

   double distanceToGo;      // Current distance to reach the object.
   double minDist2Go;        // Closest distance the palm passes by the object.
   double distanceTravelled; // Distance travelled by the palm's hand.
   double handVelocity;
   bool objectReached;      // the object has been reach?  
};


#endif /* EB366BBB_29C2_46ED_BA60_ED5FA6A69C54 */
