#pragma once

#include "Robot.h"

class Obstacle
{
public:
	static const int MAX_DISTANCE = 40;

	Obstacle(Robot* robot);
	~Obstacle();

	void avoiding(int middleDistance);

private:
	Robot* robot;
	int rightDistance;
	int leftDistance;

	void lookAround();
};