#if !defined(CONSTANTS_H)
#define CONSTANTS_H

// Seven-segment display encoding for digits 0-9
const int numeral[10] = {
  0b11111100, // 0
  0b01100000, // 1
  0b11011010, // 2
  0b11110010, // 3
  0b01100110, // 4
  0b10110110, // 5
  0b10111110, // 6
  0b11100000, // 7
  0b11111110, // 8
  0b11110110  // 9
};

// Pins we're using
const int numberOfSegments = 8;
const int segmentPins[numberOfSegments] = {9, 8, 7, 6, 5, 4, 3, 2}; // a, b, c, d, e, f, g, DP
const int minutePins[2] = {10, 11};
const int secondPins[2] = {12, 13};
const int buzzerPin = A5;
const int pauseButtonPin = A4;
const int resetButtonPin = A3;

// Constants
const int startingMinutes = 20;
const int startingSeconds = 0;
const int countdownDurationSeconds = 20;
const long secondInterval = 1000; // 1 second

#endif