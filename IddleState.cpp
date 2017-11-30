//
// Created by alex on 11/28/17.
//

#include "IddleState.h"
#include "Roaster.h"
#include "RoastingProfile.h"

IddleState::IddleState() {
  startButton = new Button(START_PIN, true, true, 20);
}

IddleState *IddleState::instance() {
    static IddleState iddle_instance;
    return &iddle_instance;
}

void IddleState::run() {
   
  startButton->read();

  if (startButton->wasReleased()) {       
      Serial.println("Iddle state");
      Roaster::instance()->startRoast(RoastingProfile::instance());
  }

}

IddleState::~IddleState() {
  delete startButton;
}

