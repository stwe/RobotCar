#include "Robot.h"
#include "Obstacle.h"

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
Obstacle* obstacle;
int middleDistance;

void setup()
{
	myRobot = new Robot();
	myRobot->setup();

	myRobot->servomotor->lookMiddle();
	myRobot->drive->setSpeed(Drive::MIN_SPEED);

	obstacle = new Obstacle(myRobot);
}


void loop()
{
	// look middle
	myRobot->servomotor->lookMiddle();

	// and get distance
	middleDistance = myRobot->upperFrontUltrasonic->getDistance();

	// print distance to LCD
	myRobot->lcd->clearDisplay();
	myRobot->lcd->setTextSize(2);
	myRobot->lcd->setTextColor(WHITE);
	myRobot->lcd->setCursor(0, 0);
	myRobot->lcd->println(middleDistance);
	myRobot->lcd->display();
	delay(1);

	// obstacle avoiding
	if (middleDistance < Obstacle::MAX_DISTANCE) {
		// decide which direction to go
		obstacle->avoiding(middleDistance);
	}
	else {
		// go forward
		myRobot->drive->forward();
	}
}
