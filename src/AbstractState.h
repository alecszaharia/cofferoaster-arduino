//
// Created by alex on 11/29/17.
//

#ifndef ROASTER_STATEINTERFACE_H
#define ROASTER_STATEINTERFACE_H

#include "Lcd.h"

class AbstractState {
public:
    virtual void on_set() {};
    virtual void on_unset() { Lcd::instance()->clear(); };
    virtual void run() = 0;
    virtual ~AbstractState(){ }
};

#endif //ROASTER_STATEINTERFACE_H
