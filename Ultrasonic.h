#pragma once

#include <Arduino.h>

class Ultrasonic
{
public:
	struct Config
	{
		int echo;
		int trigger;

		Config()
			: echo(A4)
			, trigger(A5)
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