#pragma once

#include "Drive.h"
#include "Ultrasonic.h"

class Robot
{
public:
	Robot() {};
	virtual ~Robot() {};

	Drive drive;

	Ultrasonic leftUltrasonic;
	Ultrasonic middleUltrasonic;
	Ultrasonic rightUltrasonic;

	void setup();
private:
};