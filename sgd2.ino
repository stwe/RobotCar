#include "Adafruit_SSD1306.h"
#include "Robot.h"

#define OLED_RESET 4
#define SAFE 30
#define BACK 0
#define FORW 1
#define LEFT 2
#define RIGHT 3

#define getMax(a, b) ((a) > (b) ? (a) : (b))

Adafruit_SSD1306 lcd(OLED_RESET);
Robot myRobot;

/*

------------------------------
Motor Pin-Setup (class: Drive)
------------------------------
enA:    11 - grau
in1:     9 - blau
in2:     8 - grün
enB:     5 - lila
in3:     7 - schwarz
in4:     6 - weiß
speed: 130

-------------------------------------
US Pin-Setup Left (class: Ultrasonic)
-------------------------------------
trigger: A0
echo:    A1

---------------------------------------
US Pin-Setup Middle (class: Ultrasonic)
---------------------------------------
trigger: 2
echo:    3

--------------------------------------
US Pin-Setup Right (class: Ultrasonic)
--------------------------------------
trigger: A2
echo:    A3

-------------
LCD Pin-Setup
-------------
scl: => A5
sda: => A4

*/

void setup()
{
	lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);

	myRobot.setup();
	myRobot.drive.setSpeed(Drive::MIN_SPEED);
}

int explore() 
{
	int distL = getMax(myRobot.leftUltrasonic.getDistanceByTemp(21.0), myRobot.leftUltrasonic.getDistanceByTemp(21.0));
	delay(50);
	int distM = getMax(myRobot.middleUltrasonic.getDistanceByTemp(21.0), myRobot.middleUltrasonic.getDistanceByTemp(21.0));
	delay(50);
	int distR = getMax(myRobot.rightUltrasonic.getDistanceByTemp(21.0), myRobot.rightUltrasonic.getDistanceByTemp(21.0));
	delay(50);

	lcd.clearDisplay();
	lcd.setTextSize(1);
	lcd.setTextColor(WHITE);
	lcd.setCursor(0, 0);
	lcd.print("Left: ");
	lcd.println(distL);
	lcd.print("Middle: ");
	lcd.println(distM);
	lcd.print("Right: ");
	lcd.println(distR);
	lcd.println();
	lcd.display();

	if (distM <= SAFE && distL <= SAFE && distR <= SAFE) {
		lcd.print("ZURÜCK");
		lcd.display();
		return BACK;
	}

	if (distM <= SAFE) {
		if (distL >= distR) {
			lcd.print("LINKS");
			lcd.display();
			return LEFT;
		}
		else {
			lcd.print("RECHTS");
			lcd.display();
			return RIGHT;
		}

		lcd.print("ZURÜCK");
		lcd.display();
		return BACK;
	}
	else if (distL <= SAFE) {
		lcd.print("RECHTS");
		lcd.display();
		return RIGHT;
	}
	else if (distR <= SAFE) {
		lcd.print("LINKS");
		lcd.display();
		return LEFT;
	}
	else {
		lcd.print("VORWÄRTS");
		lcd.display();
		return FORW;
	}
}

void loop()
{
	int i = explore();

	switch (i) {
		case BACK:
			myRobot.drive.back();
			delay(500);
			break;

		case FORW:
			myRobot.drive.forward();
			break;

		case LEFT:
			myRobot.drive.left();
			delay(1000);
			break;

		case RIGHT:
			myRobot.drive.right();
			delay(1000);
			break;

		default:
			lcd.print("Entscheidung: ! KEINE !");
			lcd.display();
	}

	delay(100);
}
