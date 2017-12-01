//
// Created by alex on 12/1/17.
//

#include "Lcd.h"
#include <LiquidCrystal_I2C.h>

static Lcd* Lcd::instance() {
   static Lcd lcd;
    return &lcd;
}

Lcd::Lcd() {
   lcd_cristal->init();     
}

Lcd::~Lcd() {

  delete lcd_cristal;
  
  if(page)
    delete page;
}

LcdPageInterface *Lcd::getPage() const {
    return page;
}

void Lcd::setPage(LcdPageInterface *page) {
    
    Lcd::page = page;    
    Lcd::page->setLcd( lcd_cristal );
}

void Lcd::render() {
       
    //lcd_cristal->clear();
    
    if(page)
    {      
      getPage()->build();
      
    }
    else 
    {
      
    }
}

