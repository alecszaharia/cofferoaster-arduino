//
// Created by alex on 11/29/17.
//
//
#ifndef ROASTER_ROASTINGSTATE_H
#define ROASTER_ROASTINGSTATE_H

#include <JC_Button.h>
#include "AbstractState.h"
#include "RoastingProfile.h"
#include "LcdRoastingPage.h"
#include "StopWatch.h"

#include "Arduino.h"
#include "JC_Button.h"
#include "Roaster.h"
#include "PINDefinitions.h"
#include "Thermocouple.h"




const int vccPin = 3;
const int gndPin = 2;

class RoastingState : public AbstractState {

private:
    RoastingProfile *profile;
    Button *stopButton, *coolingButton;
    Thermocouple *bt_thermocouple;
    Thermocouple *et_thermocouple;
    LcdRoastingPage lcd_page;
    StopWatch stopWatch;

    State state = STOPPED;

    void init();

public:

    static RoastingState *instance();

    RoastingState();

    RoastingState(RoastingProfile *profile);

    ~RoastingState();

    void setProfile(RoastingProfile *intervals);

    void run() override;

    void on_set() override;

    void on_unset() override;
};


#endif //ROASTER_ROASTINGSTATE_H
