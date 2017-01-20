#include <Servo.h>

#include "Servomotor.h"

void Servomotor::pinSetup()
{
	servo.attach(pin);
}

void Servomotor::lookRight()
{
	servo.write(right);
}

void Servomotor::lookLeft()
{
	servo.write(left);
}

void Servomotor::lookMiddle()
{
	servo.write(middle);
}

void Servomotor::lookByAngle(int angle)
{
	servo.write(angle);
}
