#ifndef _PID_H
#define _PID_H

#include "constants.h"
#include "debugable.h"
#include "statemanager.h"

class Input : public Debugable {
public:
	Input(StateManager*);

	void init();

	void loop(unsigned long);

private:
	StateManager* stateManager;

	volatile int lastEncoded = 0;
	volatile long encoderValue = 0;
	long lastEncoderValue = 0;
	bool buttonPressed = false;
	bool lastButtonPressed = false;


	void updateEncoder();
	void checkChanges();

};
#endif