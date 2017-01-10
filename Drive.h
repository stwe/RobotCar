#pragma once

class Drive
{
public:
	static const int MIN_SPEED = 90;
	static const int NORMAL_SPEED = 130;
	static const int MAX_SPEED = 255;

	struct Config
	{
		int speed;
		int enA;
		int in1;
		int in2;
		int enB;
		int in3;
		int in4;

		Config()
			: speed(NORMAL_SPEED)
			, enA(11)
			, in1(9)
			, in2(8)
			, enB(5)
			, in3(7)
			, in4(6)
		{}
	};

	Drive(const Config& config);
	virtual ~Drive();

	void setup();
	void forward();
	void back();
	void left();
	void right();
	void stop();
	void setSpeed(int speed);
	int getSpeed();

private:
	int speed;
	int enA;
	int in1;
	int in2;
	int enB;
	int in3;
	int in4;
};