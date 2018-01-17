//
// Created by alex on 12/1/17.
//

#include "LcdRoastingPage.h"
#include "Heater.h"


LcdRoastingPage::LcdRoastingPage() {
    getLcd()->clear();
}

LcdRoastingPage::~LcdRoastingPage() {

}

void LcdRoastingPage::draw() {

    // Temperature
    getLcd()->setCursor(0, 0);
    String _t = String(getBtTemperature(), 0);
    getLcd()->print("BT:" + _t + "    ");

    getLcd()->setCursor(7, 0);
    _t = String(getEtTemperature(), 0);
    getLcd()->print("ET:" + _t + "    ");

    getLcd()->setCursor(14, 0);
    getLcd()->print("SV:" + String(roasting_profile->getCurrentInterval()->getTemperatureSV()));


    // Roasting time
    getLcd()->setCursor(0, 1);
    getLcd()->print("RT:" + stopWatch->getDisplayString());

    // roasting septs
    getLcd()->setCursor(10, 1);
    getLcd()->print("RI:" + String(roasting_profile->getCurrent()+1) + "/" + String(roasting_profile->getCount()));

    // Fan speed
    getLcd()->setCursor(0, 2);
    getLcd()->print("FS:" + String(roasting_profile->getCurrentInterval()->getFanSpeed() ) );

    // Fan speed
    getLcd()->setCursor(0, 3);
    getLcd()->print( Heater::instance()->getElementState()?"HEATING":"" );

}


void LcdRoastingPage::setStopWatch(StopWatch &stopWatch) {
    LcdRoastingPage::stopWatch = &stopWatch;
}

void LcdRoastingPage::setBtThermocouple(Thermocouple &thermocouple) {
    LcdRoastingPage::bt_thermocouple = &thermocouple;
}

void LcdRoastingPage::setEtThermocouple(Thermocouple &thermocouple) {
    LcdRoastingPage::et_thermocouple = &thermocouple;
}


double LcdRoastingPage::getBtTemperature() const {
    return bt_thermocouple->readCelsius();
}

double LcdRoastingPage::getEtTemperature() const {
    return et_thermocouple->readCelsius();
}

void LcdRoastingPage::setRoastingProfile(RoastingProfile &profile) {
    LcdRoastingPage::roasting_profile = &profile;
}
