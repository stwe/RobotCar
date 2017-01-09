#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(const Config& config, String name) 
	: echo(config.echo)
	, trigger(config.trigger)
	, name(name)
{}

Ultrasonic::~Ultrasonic()
{}

void Ultrasonic::setup()
{
	pinMode(echo, INPUT);
	pinMode(trigger, OUTPUT);
}

int Ultrasonic::getDistance()
{
	digitalWrite(trigger, LOW);
	delay(2);
	digitalWrite(trigger, HIGH);
	delay(10);
	digitalWrite(trigger, LOW);

	float distance = pulseIn(echo, HIGH);
	float result = (distance / 2.0) * 0.03432;

	return (int)result;
}

int Ultrasonic::getDistanceByTemp(float temp)
{
	digitalWrite(trigger, LOW);
	delay(2);
	digitalWrite(trigger, HIGH);
	delay(10);
	digitalWrite(trigger, LOW);

	float speed = (331.5 + (0.6 * temp)) / 10000.0;

	float distance = pulseIn(echo, HIGH);
	float result = (distance / 2.0) * speed;

	return (int)result;
}

String Ultrasonic::getName()
{
	return name;
}
