//
// Created by alex on 11/29/17.
//

#include "RoastingState.h"
#include "Roaster.h"

RoastingState *RoastingState::instance() {
   static RoastingState roasting_instance;
    return &roasting_instance;
}

void RoastingState::setProfile(RoastingProfile *aprofile) {
  RoastingState::profile = aprofile;
}

RoastingState::RoastingState() {
  stopButton = new Button(STOP_PIN, true, true, 20);
}

void RoastingState::run() {

  stopButton->read();

  if (stopButton->wasReleased()) {     
    Serial.println("Stop roast");  
      Roaster::instance()->stopRoast();
  }
}

RoastingState::~RoastingState() {
  delete stopButton;  
}
