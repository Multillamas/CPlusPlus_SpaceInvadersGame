#include "Clock.h"
#include <time.h>

Clock::Clock() {
	this->startTime = 0;
	this->endTime = 0;
}

void Clock::startCountdown(int time) {
	this->startTime = clock(); // we get a current time
	this->endTime = this->startTime + time; //we add 33 seconds
}

void Clock::waitForCountdown() {
	//wait until the current time has passed the target end time
	while (true) {
		if (endTime <= clock()) {
			return;
		}
	}
}