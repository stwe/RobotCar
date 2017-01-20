#pragma once

#include <Servo.h>

class Servomotor
{
public:
	struct Config
	{
		int pin;
		int right;
		int left;
		int middle;

		Config()
			: pin(3)
			, right(10)
			, left(170)
			, middle(90)
		{}
	};

	Config config;
	Servo servo;

	Servomotor()
		: pin(config.pin)
		, right(config.right)
		, left(config.left)
		, middle(config.middle)
	{};

	virtual ~Servomotor() {};

	void pinSetup();
	void lookRight();
	void lookLeft();
	void lookMiddle();
	void lookByAngle(int angle);

private:
	int pin;
	int right;
	int left;
	int middle;
};