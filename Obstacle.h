#pragma once

#include "Robot.h"

class Obstacle
{
public:
	static const int MAX_DISTANCE = 40;

	int rightDistance;
	int leftDistance;
	int middleDistance;

	Obstacle(Robot robot)
		: robot(robot)
		, rightDistance(0)
		, leftDistance(0)
		, middleDistance(0)
	{};

	virtual ~Obstacle() {};

	void avoiding(int middleDistance);
	void lookAround();

	void lookWhileDriving(float temp = 20.0);
	void lookAfterStop(float temp = 20.0);

private:
	Robot robot;
};