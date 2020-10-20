//
// Created by alex on 12/1/17.
//

#include "Lcd.h"

Lcd *Lcd::instance() {
    static Lcd lcd;
    return &lcd;
}

Lcd::Lcd() : TimerAware(500) {
    lcd_cristal = new LiquidCrystal_I2C(0x3f, 20, 4);
    lcd_cristal->init();
    lcd_cristal->backlight();
    start();
}

Lcd::~Lcd() {
    //delete lcd_cristal;
    if (page)
        delete page;
}

LcdPageInterface *Lcd::getPage() const {
    return page;
}

void Lcd::setPage(LcdPageInterface *page) {

    Lcd::page = page;
    Lcd::page->setLcd(lcd_cristal);
}

void Lcd::handle() {

    if (page) {
        page->draw();
    }
}

void Lcd::render() {
    tick();
}


void Lcd::clear() {
    lcd_cristal->print("                                                                                ");
}

