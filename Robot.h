#pragma once

#include "Drive.h"
#include "Ultrasonic.h"
#include "Servomotor.h"

class Robot
{
public:
	Robot() {};
	virtual ~Robot() {};

	Drive drive;
	Ultrasonic upperFrontUltrasonic;
	Servomotor servomotor;

	void setup();
private:
};