//
// Created by alex on 11/28/17.
//
#include <Button.h> 
#include "StateInterface.h"
#include "LcdAware.h"
#include "LcdIddlePage.h"


#ifndef ROASTER_STATE_H
#define ROASTER_STATE_H

const int START_PIN = 12; //Connect a tactile button switch (or something similar)


class IddleState : public StateInterface {

  Button *startButton;
  LcdIddlePage lcd_page;

public:

    IddleState();

    ~IddleState();

    static IddleState* instance();

    void run() override;
};


#endif //ROASTER_STATE_H
