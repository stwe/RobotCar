#include "Ultrasonic.h"

void Ultrasonic::pinSetup()
{
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
}

int Ultrasonic::getDistance()
{
	digitalWrite(trigger, LOW);
	delayMicroseconds(2);
	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigger, LOW);

	float duration = pulseIn(echo, HIGH);

	return (int)(duration / 58.2);
}

int Ultrasonic::getDistanceByTemp(float temp)
{
	digitalWrite(trigger, LOW);
	delayMicroseconds(2);
	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigger, LOW);

	float speed = (331.5 + (0.6 * temp)) / 10000.0;

	float duration = pulseIn(echo, HIGH);
	float result = (duration / 2.0) * speed;

	return (int)result;
}