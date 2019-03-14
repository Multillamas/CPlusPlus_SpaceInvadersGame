#pragma once


//countdown for 33 ms. We are going to display them as static images.
class Clock {
public:
	Clock();
	void startCountdown(int time);
	void waitForCountdown(); //we'll wait until it hits 0. It set a value =time and check the value

private:
	int startTime;
	int endTime;
};