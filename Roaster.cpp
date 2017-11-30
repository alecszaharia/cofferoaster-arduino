//
// Created by alex on 11/28/17.
//

#include "Roaster.h"
#include "RoastingProfile.h"
#include "RoastingState.h"
#include "IddleState.h"

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
    StateInterface *pInterface = Roaster::getState();

    if(pInterface)
        pInterface->run();
}

void Roaster::startRoast(RoastingProfile *profile) {
  RoastingState *roastingState = RoastingState::instance();
  roastingState->setProfile(profile);
  Roaster::setState(roastingState);
}

void Roaster::stopRoast() {    
    Roaster::setState(IddleState::instance());
}
