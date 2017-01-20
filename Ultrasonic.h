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

	Config config;

	Ultrasonic()
		: trigger(config.trigger)
		, echo(config.echo)
	{};

	virtual ~Ultrasonic() {};

	void pinSetup();
	int getDistance();
	int getDistanceByTemp(float temp);

private:
	int echo;
	int trigger;
};