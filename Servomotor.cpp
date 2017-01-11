#include <Servo.h>

#include "Servomotor.h"

Servomotor::Servomotor(const Config& config)
	: pin(config.pin)
	, right(config.right)
	, left(config.left)
	, middle(config.middle)
{
	servo = new Servo();
	servo->attach(pin);
}

Servomotor::~Servomotor()
{
	delete servo;
	servo = 0;
}

void Servomotor::lookRight()
{
	servo->write(right);
}

void Servomotor::lookLeft()
{
	servo->write(left);
}

void Servomotor::lookMiddle()
{
	servo->write(middle);
}

void Servomotor::look(int angle)
{
	servo->write(angle);
}
