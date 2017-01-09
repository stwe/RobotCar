#include "Robot.h"

int rightDistance = 0;
int leftDistance = 0; 
int middleDistance = 0;

// Robot
Robot* myRobot;

void handleDistance()
{
	// Auto anhalten
	myRobot->drive->stop();
	delay(500);

	// Rechte Entfernung messen
	myRobot->servomotor->lookRight();
	delay(1000);
	rightDistance = myRobot->upperFrontUltrasonic->getDistance();

	// in die Mitte drehen
	delay(500);
	myRobot->servomotor->lookMiddle();
	delay(1000);

	// Linke Entfernung messen
	myRobot->servomotor->lookLeft();
	delay(1000);
	leftDistance = myRobot->upperFrontUltrasonic->getDistance();

	// in die Mitte drehen
	delay(500);
	myRobot->servomotor->lookMiddle();
	delay(1000);

	// Entfernungen auswerten
	if (rightDistance > leftDistance) {
		myRobot->drive->right();
		delay(180);
	}
	else if (rightDistance < leftDistance) {
		myRobot->drive->left();
		delay(180);
	}
	else if ((rightDistance <= 20) || (leftDistance <= 20)) {
		myRobot->drive->back();
		delay(180);
	}
	else {
		myRobot->drive->forward();
	}
}

void setup()
{
	
	myRobot->setup();
}

void loop()
{
	// Servo in die Mitte und Entfernung holen
	myRobot->servomotor->lookMiddle();

	middleDistance = myRobot->upperFrontUltrasonic->getDistance();

	// Korrektur, wenn die Entfernung unter 20cm. Ansonsten Motor-Pins auf forward() schalten
	if (middleDistance <= 20) {
		handleDistance();
	} else {		
		myRobot->drive->forward();
	}
}
