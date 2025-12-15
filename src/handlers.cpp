#include <Arduino.h>
#include "constants.h"
#include "handlers.h"


void timerChange(int &currentMinutes, int &currentSeconds, bool &lookAtScreen) {
  if(!lookAtScreen) {
    // Change it back to 20 minutes as user should now be done resting
    currentMinutes = startingMinutes;
    currentSeconds = startingSeconds;
    lookAtScreen = true;
  } else {
    // Change it to 20 seconds for the countdown for user to look away
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