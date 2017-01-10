#pragma once

#include <Arduino.h>

class Ultrasonic
{
public:
	struct Config
	{
		int trigger;
		int echo;

		Config()
			: trigger(A0)
			, echo(A1)
		{}
	};

	Ultrasonic(const Config& config, String name);
	virtual ~Ultrasonic();

	void setup();
	int getDistance();
	int getDistanceByTemp(float temp);
	String getName();

private:
	String name;
	int echo;
	int trigger;
};