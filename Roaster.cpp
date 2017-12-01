//
// Created by alex on 11/28/17.
//

#include "Roaster.h"
#include "RoastingProfile.h"
#include "RoastingState.h"
#include "IddleState.h"
#include "Lcd.h"

Roaster::Roaster() {
    stopRoast();
}

Roaster *Roaster::instance() {
    static Roaster roaster_instance;
    return &roaster_instance;
}

StateInterface* Roaster::getState() const {
    return Roaster::state;
}

void Roaster::setState(StateInterface *state) {
    Roaster::state = state;
}

void Roaster::run() {

    StateInterface *pstate = getState();

    if(pstate)
    {
      pstate->run();          
    }   

   
    Lcd::instance()->render();
}

void Roaster::startRoast(RoastingProfile *profile) {
  RoastingState *roastingState = RoastingState::instance();  
  roastingState->setProfile(profile);
  setState(roastingState);
}

void Roaster::stopRoast() {    
    Roaster::setState(IddleState::instance());
}
