//
// Created by alex on 11/29/17.
//
//
#include <Button.h> 
#include "StateInterface.h"
#include "RoastingProfile.h"
#include "LcdRoastingPage.h"

#ifndef ROASTER_ROASTINGSTATE_H
#define ROASTER_ROASTINGSTATE_H

const int STOP_PIN = 12; //Connect a tactile button switch (or something similar)

class RoastingState : public StateInterface {

private:
    RoastingProfile *profile;
    Button *stopButton;
    LcdRoastingPage lcd_page;

public:

    static RoastingState* instance(); 

    RoastingState();
    
    ~RoastingState();

    void setProfile(RoastingProfile *intervals);

    void run() override;
};


#endif //ROASTER_ROASTINGSTATE_H
