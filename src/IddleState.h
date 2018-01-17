//
// Created by alex on 11/28/17.
//

#ifndef ROASTER_STATE_H
#define ROASTER_STATE_H

#include "Roaster.h"
#include "PINDefinitions.h"
#include <Button.h>
#include "AbstractState.h"
#include "LcdAware.h"
#include "LcdIddlePage.h"


const int START_PIN = 12; //Connect a tactile button switch (or something similar)

class IddleState : public AbstractState {

    Button *startButton;
    Thermocouple *thermocouple;
    LcdIddlePage lcd_page;

    IddleState();

public:

    static IddleState *instance();

    ~IddleState();

    void run() override;

    void on_set() override ;
};


#endif //ROASTER_STATE_H
