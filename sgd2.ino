#include "Robot.h"

int rightDistance = 0;
int leftDistance = 0; 
int middleDistance = 0;

/*

------------------------------
Motor Pin-Setup (class: Drive)
------------------------------
enA:    11
in1:     9
in2:     8
enB:     4
in3:     7
in4:     6
speed: 130

-----------------------------------
Servo Pin-Setup (class: Servomotor)
-----------------------------------
pin: 3

--------------------------------
US Pin-Setup (class: Ultrasonic)
--------------------------------
echo:    A0
trigger: A1

-------------
LCD Pin-Setup
-------------
scl: => A5
sda: => A4

*/

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
	myRobot = new Robot();
	myRobot->setup();
}

void loop()
{
	// Servo in die Mitte und Entfernung holen
	myRobot->servomotor->lookMiddle();

	// Enternung messen
	middleDistance = myRobot->upperFrontUltrasonic->getDistance();

	// ... und auf dem Lcd ausgeben
	myRobot->lcd->clearDisplay();
	myRobot->lcd->setTextSize(2);
	myRobot->lcd->setTextColor(WHITE);
	myRobot->lcd->setCursor(0, 0);
	myRobot->lcd->println(middleDistance);
	myRobot->lcd->display();
	delay(1);

	// Korrektur, wenn die Entfernung unter 20cm. Ansonsten Motor-Pins auf forward() schalten
	/*
	if (middleDistance <= 20) {
		handleDistance();
	} else {		
		myRobot->drive->forward();
	}
	*/
}
