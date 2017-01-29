#include <Arduino.h>

#include "Drive.h"

void Drive::pinSetup()
{
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

	stop();
}

void Drive::forward()
{
	analogWrite(enA, speed);
	analogWrite(enB, speed);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

	stopped = false;

	Serial.println("forward");
}

void Drive::back()
{
	analogWrite(enA, speed);
	analogWrite(enB, speed);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

	stopped = false;

	Serial.println("back");
}

void Drive::left()
{
	analogWrite(enA, speed);
	analogWrite(enB, speed);

	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

	stopped = false;

	Serial.println("left");
}

void Drive::right()
{
	analogWrite(enA, speed);
	analogWrite(enB, speed);

	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

	stopped = false;

	Serial.println("right");
}

void Drive::stop()
{
	analogWrite(enA, LOW);
	analogWrite(enB, LOW);

	stopped = true;

	Serial.println("stop");
}

void Drive::setSpeed(int speed)
{
	if (speed < MIN_SPEED) {
		speed = MIN_SPEED;
	}

	if (speed > MAX_SPEED) {
		speed = MAX_SPEED;
	}

	this->speed = speed;
}

int Drive::getSpeed()
{
	return speed;
}

bool Drive::getStopped()
{
	return stopped;
}
