#include <FiniteStateMachine.h>
#include <Metro.h>

Metro ledOnTimer(2000);
Metro ledOffTimer(1000);

void enterLedOn();
void updateLedOn();
void exitLedOn();

void enterLedOff();
void updateLedOff();
void exitLedOff();

State LedOn = State(enterLedOn, updateLedOn, exitLedOn);
State LedOff = State(enterLedOff, updateLedOff, exitLedOff);

FiniteStateMachine LedFlasher = FiniteStateMachine(LedOn);

void enterLedOn() {

}

void updateLedOn() {
	if (ledOnTimer.check()) {
		digitalWrite(D4, 1);
		ledOffTimer.reset();
		LedFlasher.transitionTo(LedOff);
	}
}

void exitLedOn() {

}



void enterLedOff() {

}

void updateLedOff() {
	if (ledOffTimer.check()) {
		digitalWrite(D4, 0);
		ledOnTimer.reset();
		LedFlasher.transitionTo(LedOn);
	}
	
}

void exitLedOff() {

}



void setup() {
	pinMode(D4, OUTPUT);
	ledOnTimer.reset();
	ledOffTimer.reset();
	digitalWrite(D4, 1);
	delay(2000);
	digitalWrite(14, 0);
}

void loop() {
	LedFlasher.update();
}