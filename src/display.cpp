#include <Arduino.h>
#include "display.h"
#include "constants.h"

void showMinutes(int minutes) {
  if(minutes > 99) {
    minutes = 99; // Cap at 99
  }
  int tens = minutes / 10;
  int units = minutes % 10;

  showDigit(tens, minutePins[0]);
  showDigit(units, minutePins[1]);
}

void showSeconds(int seconds) {
  if(seconds > 99) {
    seconds = 99; // Cap at 99
  }
  int tens = seconds / 10;
  int units = seconds % 10;

  showDigit(tens, secondPins[0]);
  showDigit(units, secondPins[1]);
}

void showDigit(int digit, int digitPin) {
  digitalWrite(digitPin, LOW);

  int encoding = numeral[digit];
  for(int i = 0; i < numberOfSegments; i++) {
    boolean isBitSet = bitRead(encoding, i);
    digitalWrite(segmentPins[i], isBitSet);
  }

  // if(digitPin == minutePins[1]) {
  //   // Light up the decimal point for the units digit of minutes
  //   digitalWrite(segmentPins[7], HIGH);
  // }

  delay(5);
  digitalWrite(digitPin, HIGH);
}