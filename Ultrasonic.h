#pragma once

#include <Arduino.h>

class Ultrasonic
{
public:
	Ultrasonic()
		: trigger(A0)
		, echo(A1)
	{};

	virtual ~Ultrasonic() {};

	void pinSetup();
	void setTrigger(int trigger);
	void setEcho(int echo);
	int getDistance();
	int getDistanceByTemp(float temp = 20.0);

private:
	int echo;
	int trigger;
};