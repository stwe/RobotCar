#include "Robot.h"

void Robot::setup()
{
	Serial.begin(9600);

	Serial.println("The Robot is setting up.");

	drive.pinSetup();
	upperFrontUltrasonic.pinSetup();
	servomotor.pinSetup();
}
