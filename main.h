#ifndef MAIN_H
#define MAIN_H

#include <Watchy.h>
#include "wm-data.h"

RTC_DATA_ATTR int face = 0;
uint64_t face_limit = 2;

class WatchyBrain : public Watchy {
  using Watchy::Watchy;
  public:
    void drawWatchFace();
    // void drawBattery(float batt);
    void drawAnalog();
    void drawDigital(float batt);
    void drawSteps(float batt);
    virtual void handleButtonPress();//Must be virtual in Watchy.h too
};

#include "analog.h"
#include "digital.h"
#include "steps.h"

void WatchyBrain::handleButtonPress() {
  if (guiState == WATCHFACE_STATE) {
    //Up and Down switch watch faces
    uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();
    if (wakeupBit & UP_BTN_MASK) {
      face--;
      if (face < 0 ) { face = face_limit; }
      RTC.read(currentTime);
      showWatchFace(true);
      return;
    }
    if (wakeupBit & DOWN_BTN_MASK) {
      face++;
      if (face > face_limit ) { face = 0; }
      RTC.read(currentTime);
      showWatchFace(true);
      return;
    }
    if (wakeupBit & MENU_BTN_MASK) {
      Watchy::handleButtonPress();
      return;
    }
  } else {Watchy::handleButtonPress();}
  return;
}

void WatchyBrain::drawWatchFace() {
  // ** UPDATE **
  //resets step counter at midnight everyday
  if (currentTime.Hour == 00 && currentTime.Minute == 00) {
    sensor.resetStepCounter();
  }

  // ** GET BATTERY **
  float batt = (getBatteryVoltage()-3.3);
  if (batt > 1) { batt = 1; } else if (batt < 0) { batt = 0; }
  
  // ** DRAW WATCHFACE **
  if (face == 0) {
    drawAnalog();
  }
  if (face == 1) {
    drawDigital(batt);  
  }
  if (face == 2) {
    drawSteps(batt);
  }
}

#endif
