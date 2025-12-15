#include <Arduino.h>
#include "constants.h"
#include "handlers.h"


void timerChange(int &currentMinutes, int &currentSeconds, bool &lookAtScreen) {
  if(!lookAtScreen) {
    currentMinutes = startingMinutes;
    currentSeconds = startingSeconds;
    lookAtScreen = true;
  } else {
    currentMinutes = 0;
    currentSeconds = countdownDurationSeconds;
    lookAtScreen = false;
  }
}

void handleCountdown(int &currentMinutes, int &currentSeconds, unsigned long &previousMillis, bool &lookAtScreen, bool &paused) {
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= secondInterval) {
    previousMillis = currentMillis;
    currentSeconds--;
    if(currentSeconds < 0) {
      currentSeconds = 59;
      currentMinutes--;
      if(currentMinutes < 0) {
        timerChange(currentMinutes, currentSeconds, lookAtScreen);
        paused = true;
        digitalWrite(buzzerPin, HIGH); // Turn on buzzer
      }
    }
  }
}

void handlePauseButton(bool &paused) {
  paused = !paused;
  digitalWrite(buzzerPin, LOW); // Turn off buzzer
  delay(300); // Debounce delay
}

void handleResetButton(bool &paused, int &currentMinutes, int &currentSeconds, bool &lookAtScreen) {
  paused = true;
  lookAtScreen = true;
  currentMinutes = startingMinutes;
  currentSeconds = startingSeconds;
  digitalWrite(buzzerPin, LOW); // Turn off buzzer
  delay(300); // Debounce delay
}