#include <stdio.h>    // Used for printf() statements
#include <wiringPi.h> // Include WiringPi library!
#include <iostream>
#include <softPwm.h>

using namespace std;
// Pin number declarations. We're using the Broadcom chip pin numbers.
const int motor_left1 = 27; // PWM LED - Broadcom pin 18, P1 pin 12
const int motor_left2 = 17; // PWM LED - Broadcom pin 18, P1 pin 12
const int motor_left_speed = 22; // PWM LED - Broadcom pin 18, P1 pin 12
const int motor_right1 = 24; // PWM LED - Broadcom pin 18, P1 pin 12
const int motor_right2 = 23; // Regular LED - Broadcom pin 23, P1 pin 16
const int motor_right_speed = 18; // Active-low button - Broadcom pin 17, P1 pin 11

void init();
void forward(int speed, float time);
void left_turn(int degree, float time);
void right_turn(int degree, float time);
void backward(int speed, float time);

int main()
{
	forward(150, 2500);
	left_turn(150, 2000);
	right_turn(150, 2000);
	left_turn(100, 1000);
	right_turn(200, 1500);
	backward(200, 1000);
    return 0;
}

void init()
{
	wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers
	softPwmCreate(motor_left_speed, 0, 200);
	softPwmCreate(motor_right_speed, 0, 200);
	pinMode(motor_left1, OUTPUT);  
	pinMode(motor_left2, OUTPUT); 
	pinMode(motor_right1, OUTPUT); 
	pinMode(motor_right2, OUTPUT); 
}


void backward(int speed, float time)
{
	init();
	digitalWrite(motor_left1, HIGH);
	digitalWrite(motor_left2, LOW);
	digitalWrite(motor_right1, HIGH);
	digitalWrite(motor_right2, LOW);
	softPwmWrite(motor_right_speed, speed);
	softPwmWrite(motor_left_speed, speed);
	cout << "backwarding" << endl;

	delay(time);
	stop();
}


void left_turn(int degree, float time)
{
	init();
	digitalWrite(motor_left1, LOW);
	digitalWrite(motor_left2, LOW);
	digitalWrite(motor_right1, LOW);
	digitalWrite(motor_right2, HIGH);

	softPwmWrite(motor_right_speed, degree);
	cout << "left_turn" << endl;

	delay(time);
	stop();
}

void right_turn(int degree, float time)
{
	init();
	digitalWrite(motor_left1, LOW);
	digitalWrite(motor_left2, HIGH);
	digitalWrite(motor_right1, LOW);
	digitalWrite(motor_right2, LOW);

	softPwmWrite(motor_left_speed, degree);
	cout << "right_turn" << endl;

	delay(time);
	stop();
}

void forward(int speed, float time)
{
	init();
	digitalWrite(motor_left1, LOW);
	digitalWrite(motor_left2, HIGH);
	digitalWrite(motor_right1, LOW);
	digitalWrite(motor_right2, HIGH);
	softPwmWrite(motor_right_speed, speed);
	softPwmWrite(motor_left_speed, speed);
	cout << "forwarding" << endl;

	delay(time);
	stop();
}

void stop()
{
	softPwmWrite(motor_right_speed, 0);
	softPwmWrite(motor_left_speed, 0);
	digitalWrite(motor_left1, LOW);
	digitalWrite(motor_left2, LOW);
	digitalWrite(motor_right1, LOW);
	digitalWrite(motor_right2, LOW);
}











