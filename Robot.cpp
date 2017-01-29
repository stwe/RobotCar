#include "Robot.h"

void Robot::setup()
{
	Serial.begin(9600);
	Serial.println("The Robot is setting up.");

	drive.pinSetup();

	leftUltrasonic.setTrigger(A0);
	leftUltrasonic.setEcho(A1);

	middleUltrasonic.setTrigger(2);
	middleUltrasonic.setEcho(3);

	rightUltrasonic.setTrigger(A2);
	rightUltrasonic.setEcho(A3);

	leftUltrasonic.pinSetup();
	middleUltrasonic.pinSetup();
	rightUltrasonic.pinSetup();
}
