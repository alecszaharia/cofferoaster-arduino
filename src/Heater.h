//
// Created by alex on 12/9/17.
//

#ifndef COFFEROASTER_HEATER_H
#define COFFEROASTER_HEATER_H

#include <Roaster.h>
#include <PID_v1.h>
#include "TimerAware.h"
#include "PINDefinitions.h"
#include "Thermocouple.h"

const int HEATER_WINDOW = 200;


typedef enum {
     INACTIVE = 0, ACTIVE = 1
} HeatingElementState;


class Heater {
    PID *pid;
    State state = STOPPED;
    double setValue = 1, Input=0, Output=0;
    double Kp=PID_KP, Ki=PID_KI, Kd=PID_KD;
    unsigned long startTime = millis();
    HeatingElementState elementState;
    Thermocouple *thermocouple;

    State getState() const;
    void setState(State state);

public:
    static Heater *instance();

    Heater();

    ~Heater();

    void run();

    void on();

    void off();

    double getSetValue() const;

    void setSetValue(double setValue);

    double getInput() const;

    void setInput(double Input);

    double getOutput() const;

    void setOutput(double Output);

    double getKp() const;

    void setKp(double Kp);

    double getKi() const;

    void setKi(double Ki);

    double getKd() const;

    void setKd(double Kd);

    HeatingElementState getElementState() const;

    void setElementState(HeatingElementState elementState);

    void setThermocouple(Thermocouple *thermocouple);

};


#endif //COFFEROASTER_HEATER_H
