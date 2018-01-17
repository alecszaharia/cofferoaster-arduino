//
// Created by alex on 11/29/17.
//
#include "RoastingState.h"
#include "Heater.h"

RoastingState *RoastingState::instance() {
    static RoastingState instance;
    return &instance;
}

void RoastingState::setProfile(RoastingProfile *aprofile) {
    RoastingState::profile = aprofile;
}

void RoastingState::on_set() {

    Serial.println("Starting roast profile");
    state = RUNNING;
    stopWatch.start();
    profile->startProfile();
}

void RoastingState::on_unset() {
    AbstractState::on_unset();

    stopWatch.reset();
    profile->stopProfile();
}

void RoastingState::init() {

    pinMode(vccPin, OUTPUT);
    digitalWrite(vccPin, HIGH);
    pinMode(gndPin, OUTPUT);
    digitalWrite(gndPin, LOW);

    //lcd_page = new LcdRoastingPage();
    stopButton = new Button(STOP_PIN, true, true, 20);
    coolingButton = new Button(COOLING_PIN, true, true, 20);
    bt_thermocouple = new Thermocouple(THERMO_CLK, BT_THERMO_CS, THERMO_DO);
    et_thermocouple = new Thermocouple(THERMO_CLK, ET_THERMO_CS, THERMO_DO);

    Heater::instance()->setThermocouple(bt_thermocouple);

    stopWatch.start();

    lcd_page.setStopWatch(stopWatch);
    lcd_page.setBtThermocouple(*bt_thermocouple);
    lcd_page.setEtThermocouple(*et_thermocouple);
}

RoastingState::RoastingState() {
    init();
}

RoastingState::RoastingState(RoastingProfile *_profile) {
    init();
    setProfile(_profile);
    lcd_page.setRoastingProfile(*profile);
}

void RoastingState::run() {

    if (!stopButton->wasReleased() && stopButton->pressedFor(5000)) {
        Serial.println("Stop roast -> Iddele");
        Roaster::instance()->stopRoast();
        return;
    }

    if (coolingButton->wasReleased()) {
        Serial.println("Stop roast -> Cooling State");
        profile->runLastInterval();
    }

    stopButton->read();
    coolingButton->read();

    // the profile is stoppped the
    if (profile->getState() == STOPPED) {
        stopWatch.stop();
    } else {
        stopWatch.tick();
        profile->run();
    }


    Lcd::instance()->setPage(&lcd_page);

    Lcd::instance()->render();
}

RoastingState::~RoastingState() {
    delete stopButton;
    delete coolingButton;
    delete bt_thermocouple;
    delete et_thermocouple;
    delete profile;
}
