//
// Created by alex on 12/1/17.
//



#ifndef ROASTER_LCDROASTINGPAGE_H
#define ROASTER_LCDROASTINGPAGE_H


#include <LiquidCrystal_I2C.h>
#include "LcdPageInterface.h"
#include "MillisTimer.h"
#include "StopWatch.h"
#include "RoastingProfile.h"
#include "Thermocouple.h"


class LcdRoastingPage: public LcdPageInterface {

    StopWatch *stopWatch;
    Thermocouple *bt_thermocouple;
    Thermocouple *et_thermocouple;
    RoastingProfile *roasting_profile;

    double getBtTemperature() const;
    double getEtTemperature() const;

public:
    LcdRoastingPage();

    ~LcdRoastingPage();
    
    void draw() override;

    void setStopWatch(StopWatch &stopWatch);

    void setBtThermocouple(Thermocouple &thermocouple);
    void setEtThermocouple(Thermocouple &thermocouple);

    void setRoastingProfile(RoastingProfile &profile);
};




#endif //ROASTER_LCDROASTINGPAGE_H
