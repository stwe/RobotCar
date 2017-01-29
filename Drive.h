#pragma once

class Drive
{
public:
	static const int MIN_SPEED = 90;
	static const int NORMAL_SPEED = 130;
	static const int MAX_SPEED = 255;
	static const int TURNTIME = 900;

	struct Config
	{
		int speed;
		int enA;
		int in1;
		int in2;
		int enB;
		int in3;
		int in4;
		bool stopped;

		Config()
			: speed(NORMAL_SPEED)
			, enA(11)
			, in1(9)
			, in2(8)
			, enB(5)
			, in3(7)
			, in4(6)
			, stopped(false)
		{}
	};

	Config config;

	Drive()
		: speed(config.speed)
		, enA(config.enA)
		, in1(config.in1)
		, in2(config.in2)
		, enB(config.enB)
		, in3(config.in3)
		, in4(config.in4)
		, stopped(config.stopped)
	{};

	virtual ~Drive() {};

	void pinSetup();
	void forward();
	void back();
	void left();
	void right();
	void stop();
	void setSpeed(int speed);
	int getSpeed();
	bool getStopped();

private:
	int speed;
	int enA;
	int in1;
	int in2;
	int enB;
	int in3;
	int in4;
	bool stopped;
};