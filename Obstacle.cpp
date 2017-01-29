#include "Obstacle.h"

void Obstacle::avoiding(int middleDistance)
{
	// stop the car
	robot.drive.stop();
	delay(500);

	// look around and get right and left distances
	lookAround();

	// decide which direction to go
	if (rightDistance > leftDistance) {
		robot.drive.right();
		delay(Drive::TURNTIME);
	}
	else if (rightDistance < leftDistance) {
		robot.drive.left();
		delay(Drive::TURNTIME);
	}
	else if ((rightDistance <= MAX_DISTANCE) || (leftDistance <= MAX_DISTANCE)) {
		robot.drive.back();
		delay(Drive::TURNTIME);
	}
	else {
		robot.drive.forward();
	}
}

void Obstacle::lookAround()
{
	/*
	// look right and get distance
	robot.servomotor.lookRight();
	delay(250);
	rightDistance = robot.upperFrontUltrasonic.getDistance();

	// look middle again
	delay(250);
	robot.servomotor.lookMiddle();
	delay(250);

	// look left and get distance
	robot.servomotor.lookLeft();
	delay(250);
	leftDistance = robot.upperFrontUltrasonic.getDistance();

	// return to middle
	delay(250);
	robot.servomotor.lookMiddle();
	delay(250);
	*/
}

void Obstacle::lookWhileDriving(float temp = 20.0)
{
	/*
	// look middle and get distance
	robot.servomotor.lookMiddle();
	delay(100);
	middleDistance = robot.upperFrontUltrasonic.getDistanceByTemp(temp);
	if (middleDistance < Obstacle::MAX_DISTANCE) {
		robot.drive.stop();
	}
	delay(100);

	// look right and get distance
	robot.servomotor.lookByAngle(60);
	delay(100);
	rightDistance = robot.upperFrontUltrasonic.getDistanceByTemp(temp);
	if (rightDistance < Obstacle::MAX_DISTANCE) {
		robot.drive.stop();
	}
	delay(100);

	// look middle
	robot.servomotor.lookMiddle();
	delay(100);

	// look left and get distance
	robot.servomotor.lookByAngle(120);
	delay(100);
	leftDistance = robot.upperFrontUltrasonic.getDistanceByTemp(temp);
	if (leftDistance < Obstacle::MAX_DISTANCE) {
		robot.drive.stop();
	}
	delay(100);
	*/
}

void Obstacle::lookAfterStop(float temp)
{
	/*
	// middle
	robot.servomotor.lookMiddle();
	delay(250);
	middleDistance = robot.upperFrontUltrasonic.getDistanceByTemp(temp);
	delay(250);

	// right
	robot.servomotor.lookRight();
	delay(250);
	rightDistance = robot.upperFrontUltrasonic.getDistanceByTemp(temp);
	delay(250);

	// middle
	robot.servomotor.lookMiddle();
	delay(250);

	// left
	robot.servomotor.lookLeft();
	delay(250);
	leftDistance = robot.upperFrontUltrasonic.getDistanceByTemp(temp);
	delay(250);

	// middle
	robot.servomotor.lookMiddle();
	delay(250);
	*/
}
