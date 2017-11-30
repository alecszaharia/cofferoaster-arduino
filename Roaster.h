//
// Created by alex on 11/28/17.
//

#include "IddleState.h"
#include "RoastingProfile.h"

#ifndef ROASTER_ROASTER_H
#define ROASTER_ROASTER_H


class Roaster {

private:
    StateInterface *state;

    Roaster();

public:
    static Roaster *instance();

    void run();

    StateInterface* getState() const;

    void setState(StateInterface *state);

    void startRoast(RoastingProfile *profile);

    void stopRoast();
};


#endif //ROASTER_ROASTER_H
