#if !defined(HANDLERS_H)
#define HANDLERS_H

void timerChange(int &currentMinutes, int &currentSeconds, bool &lookAtScreen);
void handleCountdown(int &currentMinutes, int &currentSeconds, unsigned long &previousMillis, bool &lookAtScreen, bool &paused);
void handlePauseButton(bool &paused);
void handleResetButton(bool &paused, int &currentMinutes, int &currentSeconds, bool &lookAtScreen);

#endif