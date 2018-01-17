//
// Created by alex on 11/28/17.
//

#include "IddleState.h"


IddleState::IddleState() {
    IddleState::startButton = new Button(START_PIN, true, true, 30);
    IddleState::thermocouple = new Thermocouple(THERMO_CLK, BT_THERMO_CS, THERMO_DO);

    // add page to the lcd interface
    // lcd_page->setXXXX();
}

IddleState *IddleState::instance() {
    static IddleState instance;
    return &instance;
}

void IddleState::on_set() {
    Serial.println("Reset Iddle");
}


void IddleState::run() {

    if (!startButton->wasReleased() && startButton->pressedFor(2000)) {
        Serial.println("Start Roast from iddle state");


        RoastingProfile *profile = new RoastingProfile(3);

        profile->addInterval(new RoastingInterval(100, 35.0, 20000));
        profile->addInterval(new RoastingInterval(100, 45.0, 20000));
        profile->addInterval(new RoastingInterval(100, 65.0, 20000));
        profile->addInterval(new RoastingInterval(100, 0,    40000));

        Roaster::instance()->startRoast(profile);
    }

    startButton->read();

    Lcd::instance()->setPage(&lcd_page);
    Lcd::instance()->render();
}

IddleState::~IddleState() {
    delete startButton;
}

