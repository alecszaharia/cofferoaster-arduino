//
// Created by alex on 11/28/17.
//

#include "Roaster.h"

Roaster::Roaster() {
    stopRoast();
}

Roaster::~Roaster() {
    delete state;
}

Roaster *Roaster::instance() {
    static Roaster roaster_instance;
    return &roaster_instance;
}

AbstractState *Roaster::getState() const {
    return Roaster::state;
}

void Roaster::setState(AbstractState *_state) {

    if(state)
    {
        Roaster::state->on_unset();
    }

    Roaster::state = _state;
    _state->on_set();
}

void Roaster::run() {

    AbstractState *pstate = getState();

    if (pstate) {
        pstate->run();
    }
}

void Roaster::startRoast(RoastingProfile *profile) {

    Serial.println("Profile intervals: "+String(profile->getCount()));
    RoastingState *roastingState = new RoastingState(profile);
    Roaster::setState(roastingState);
}

void Roaster::stopRoast() {
    IddleState *pState = IddleState::instance();
    Roaster::setState(pState);
}
