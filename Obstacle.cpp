#include "Obstacle.h"

Obstacle::Obstacle(Robot* robot)
	: robot(robot)
	, rightDistance(0)
	, leftDistance(0)
{}

Obstacle::~Obstacle()
{}

void Obstacle::avoiding(int middleDistance)
{
	// stop the car
	robot->drive->stop();
	delay(500);

	// look around and get right and left distances
	lookAround();

	// decide which direction to go
	if (rightDistance > leftDistance) {
		robot->drive->right();
		delay(100);
	}
	else if (rightDistance < leftDistance) {
		robot->drive->left();
		delay(100);
	}
	else if ((rightDistance <= MAX_DISTANCE) || (leftDistance <= MAX_DISTANCE)) {
		robot->drive->back();
		delay(100);
	}
	else {
		robot->drive->forward();
	}
}

void Obstacle::lookAround()
{
	// look right and get distance
	robot->servomotor->lookRight();
	delay(500);
	rightDistance = robot->upperFrontUltrasonic->getDistance();

	// look middle again
	delay(500);
	robot->servomotor->lookMiddle();
	delay(500);

	// look left and get distance
	robot->servomotor->lookLeft();
	delay(500);
	leftDistance = robot->upperFrontUltrasonic->getDistance();

	// return to middle
	delay(500);
	robot->servomotor->lookMiddle();
	delay(500);
}
