#pragma once

#include <Adafruit_SSD1306.h>

#include "Drive.h"
#include "Ultrasonic.h"
#include "Servomotor.h"

#define OLED_RESET 4

class Robot
{
public:
	Robot();
	virtual ~Robot();

	Drive* drive;
	Ultrasonic* upperFrontUltrasonic;
	Adafruit_SSD1306* lcd;
	Servomotor* servomotor;

	void setup();
private:
};