//
// Created by alex on 12/9/17.
//

#include "Heater.h"

Heater *Heater::instance() {
    static Heater heater_instance;
    return &heater_instance;
}

Heater::Heater() {

    setKd(PID_KD);
    setKi(PID_KI);
    setKp(PID_KP);

    pid = new PID(&Input, &Output, &setValue, Kp, Ki, Kd, DIRECT);    
    pid->SetOutputLimits(0, HEATER_WINDOW);
    
    off();
}

Heater::~Heater() {
    delete pid;
}

void Heater::on() {
    Serial.println("Heater Active");
    setState(RUNNING);
    pid->SetMode(AUTOMATIC);
    startTime = millis();
}

void Heater::off() {
    Serial.println("Heater Inactive");
    setState(STOPPED);
    setElementState(INACTIVE);
    pid->SetMode(MANUAL);
    digitalWrite(PID_RELAY, LOW);
}

void Heater::run() {

    if (state == STOPPED) return;

    pid->Compute();

    Input = thermocouple->readCelsius();

    unsigned long checkTime = millis() - startTime ;

    if (checkTime > HEATER_WINDOW) {

        //time to shift the Relay Window
        startTime += HEATER_WINDOW;
    }

    elementState = (Output > checkTime)?ACTIVE:INACTIVE;

    //Serial.println("Input:"+String(Input) + " --- SV:"+String(setValue) + " --- Out:"+String(Output) + " --- Check:"+String(checkTime) + " --- Element:"+String(elementState) );

    digitalWrite(PID_RELAY, elementState);
}

State Heater::getState() const {
    return state;
}

void Heater::setState(State state) {
    Heater::state = state;
}


double Heater::getInput() const {
    return Input;
}

void Heater::setInput(double Input) {
    Heater::Input = Input;
}

double Heater::getOutput() const {
    return Output;
}

void Heater::setOutput(double Output) {
    Heater::Output = Output;
}

double Heater::getKp() const {
    return Kp;
}

void Heater::setKp(double Kp) {
    Heater::Kp = Kp;
}

double Heater::getKi() const {
    return Ki;
}

void Heater::setKi(double Ki) {
    Heater::Ki = Ki;
}

double Heater::getKd() const {
    return Kd;
}

void Heater::setKd(double Kd) {
    Heater::Kd = Kd;
}

double Heater::getSetValue() const {
    return setValue;
}

void Heater::setSetValue(double setValue) {
    Heater::setValue = setValue;
}

HeatingElementState Heater::getElementState() const {
    return elementState;
}

void Heater::setElementState(HeatingElementState elementState) {
    Heater::elementState = elementState;
}

void Heater::setThermocouple(Thermocouple *thermocouple) {
    Heater::thermocouple = thermocouple;
}
