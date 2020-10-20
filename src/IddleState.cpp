//
// Created by alex on 11/28/17.
//

#include "IddleState.h"
#include "SVRoastingInterval.h"


IddleState::IddleState() {
    startButton = new Button(START_PIN, 50, true, true);
    startButton->begin();    
    IddleState::thermocouple = new Thermocouple(THERMO_CLK, BT_THERMO_CS, THERMO_DO);
}

IddleState *IddleState::instance() {
    static IddleState instance;
    return &instance;
}

void IddleState::on_set() {
    Serial.println("Reset Iddle");
}

void IddleState::run() {
    
    startButton->read();
    
    if (startButton->pressedFor(1000) || true) {
        Serial.println("Start Roast from iddle state");

        RoastingProfile *profile = new RoastingProfile(6, *thermocouple);

        profile->addInterval(new SVRoastingInterval(100, 90000, 100.0)); //  from
        profile->addInterval(new SVRoastingInterval(100, 90000, 120.0)); //  from
        profile->addInterval(new SVRoastingInterval(100, 90000, 130.0)); //  from
        profile->addInterval(new SVRoastingInterval(100, 90000, 140.0)); //  from
        profile->addInterval(new SVRoastingInterval(100, 90000, 150.0)); //  from
        profile->addInterval(new SVRoastingInterval(100, 90000, 0.0)); //  from
        
        Roaster::instance()->startRoast(profile);
    }

    Lcd::instance()->setPage(&lcd_page);
    Lcd::instance()->render();
}

IddleState::~IddleState() {
    delete startButton;
}

