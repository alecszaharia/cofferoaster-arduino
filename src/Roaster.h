//
// Created by alex on 11/28/17.
//

#include "IddleState.h"
#include "RoastingProfile.h"
#include "RoastingState.h"
#include "AbstractState.h"



#ifndef ROASTER_ROASTER_H
#define ROASTER_ROASTER_H


class Roaster {

private:
    AbstractState *state;

    Roaster();

public:
    ~Roaster();

    static Roaster *instance();

    AbstractState* getState() const;

    void run();

    void setState(AbstractState *state);

    void startRoast(RoastingProfile *profile);

    void stopRoast();

};


#endif //ROASTER_ROASTER_H
