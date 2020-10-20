//
// Created by alex on 12/1/17.
//

#include "LcdIddlePage.h"

LcdIddlePage::LcdIddlePage() {
    getLcd()->clear();
}

LcdIddlePage::~LcdIddlePage() {

}

void LcdIddlePage::draw() {
    getLcd()->setCursor(0,0);   
    getLcd()->print("Iddle         ");    
}
