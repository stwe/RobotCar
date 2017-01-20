#include "Adafruit_SSD1306.h"
#include "Robot.h"
#include "Obstacle.h"

#define OLED_RESET 4

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

Adafruit_SSD1306 lcd(OLED_RESET);
Robot myRobot;
Obstacle obstacle(myRobot);

int middleDistanceAfterStop;
unsigned long previousMillis;
unsigned long interval;

void setup()
{
	lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);

	myRobot.setup();
	myRobot.drive.setSpeed(Drive::MIN_SPEED);
}

void loop()
{
	// start with look middle
	myRobot.servomotor.lookMiddle();

	// get right, left and middle distances
	obstacle.lookWhileDriving();

	// ... and print infos to LCD
	lcd.clearDisplay();
	lcd.setTextSize(1);
	lcd.setTextColor(WHITE);
	lcd.setCursor(0, 0);
	lcd.print("Right: ");
	lcd.println(obstacle.rightDistance);
	lcd.print("Left: ");
	lcd.println(obstacle.leftDistance);
	lcd.print("Middle: ");
	lcd.println(obstacle.middleDistance);
	lcd.display();
	delayMicroseconds(1000);

	// obstacle avoiding
	if (obstacle.rightDistance < Obstacle::MAX_DISTANCE || obstacle.leftDistance < Obstacle::MAX_DISTANCE || obstacle.middleDistance < Obstacle::MAX_DISTANCE) {
		// stop the robot
		myRobot.drive.stop();
		delay(250);
		// get distances
		obstacle.lookAfterStop();
		// decide which direction to go
		if (obstacle.rightDistance > obstacle.leftDistance) {
			myRobot.drive.right();
			delay(Drive::TURNTIME);
		}
		else if (obstacle.rightDistance < obstacle.leftDistance) {
			myRobot.drive.left();
			delay(Drive::TURNTIME);
		}
		else if ((obstacle.rightDistance <= Obstacle::MAX_DISTANCE) || (obstacle.leftDistance <= Obstacle::MAX_DISTANCE)) {
			myRobot.drive.back();
			delay(Drive::TURNTIME);
		}
		else {
			myRobot.drive.forward();
		}
	}
	else {
		// go forward
		myRobot.drive.forward();
	}
}
