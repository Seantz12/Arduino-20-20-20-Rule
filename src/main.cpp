#include <Arduino.h>
#include "constants.h"
#include "display.h"
#include "handlers.h"

// Variables
bool lookAtScreen = true;
bool paused = true;
int currentMinutes = startingMinutes;
int currentSeconds = startingSeconds;
unsigned long previousMillis = 0;

// Function definitions
void setup() {
  // Initialize digital pins as outputs
  for(int i = 0; i < numberOfSegments; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW);
  }

  for(int i = 0; i < 2; i++) {
    pinMode(minutePins[i], OUTPUT);
    pinMode(secondPins[i], OUTPUT);
  }
  
  // Initialize buzzer pin
  pinMode(buzzerPin, OUTPUT);

  // Initialize button pins
  pinMode(pauseButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
}

void loop() {
  showMinutes(currentMinutes);
  showSeconds(currentSeconds);

  if(digitalRead(pauseButtonPin) == LOW) {
    handlePauseButton(paused);
  }

  if(digitalRead(resetButtonPin) == LOW) {
    handleResetButton(paused, currentMinutes, currentSeconds, lookAtScreen);
  }

  if(!paused) {
    handleCountdown(currentMinutes, currentSeconds, previousMillis, lookAtScreen, paused);
  }
}
