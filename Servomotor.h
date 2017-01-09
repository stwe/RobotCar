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

	Servomotor(const Config& config);
	virtual ~Servomotor();

	void lookRight();
	void lookLeft();
	void lookMiddle();

private:
	Servo* servo;
	int pin;
	int right;
	int left;
	int middle;
};