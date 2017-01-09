#include "Robot.h"
#include "Servomotor.h"

Robot::Robot()
{}

Robot::~Robot()
{
	delete servomotor;
	servomotor = 0;

	delete lcd;
	lcd = 0;

	delete lowerFrontUltrasonic;
	lowerFrontUltrasonic = 0;

	delete upperFrontUltrasonic;
	upperFrontUltrasonic = 0;

	delete drive;
	drive = 0;
}

void Robot::setup()
{
	Serial.begin(9600);

	Drive::Config driveConfig;
	drive = new Drive(driveConfig);
	drive->setup();

	Ultrasonic::Config upperFrontUltrasonicConfig;
	upperFrontUltrasonicConfig.echo = A0;
	upperFrontUltrasonicConfig.trigger = A1;

	Ultrasonic::Config lowerFrontUltrasonicConfig;
	lowerFrontUltrasonicConfig.echo = A2;
	lowerFrontUltrasonicConfig.trigger = A3;

	upperFrontUltrasonic = new Ultrasonic(upperFrontUltrasonicConfig, "upperFrontUltrasonic");
	upperFrontUltrasonic->setup();

	lowerFrontUltrasonic = new Ultrasonic(lowerFrontUltrasonicConfig, "lowerFrontUltrasonic");
	lowerFrontUltrasonic->setup();

	lcd = new Adafruit_SSD1306(OLED_RESET);
	lcd->begin(SSD1306_SWITCHCAPVCC, 0x3C);

	Servomotor::Config servoConfig;
	servomotor = new Servomotor(servoConfig);
}
