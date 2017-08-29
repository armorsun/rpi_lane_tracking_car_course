#include <wiringPi.h>
#include <iostream>
#include <stdlib.h>
#define TRIG 5
#define ECHO 6

using namespace std;

void init() {
	wiringPiSetupGpio();
	//setup for broadcom pin layout
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	//TRIG pin must start LOW
	digitalWrite(TRIG, LOW);
	delay(30);
}

int get_distance() {
	digitalWrite(TRIG, HIGH);
	delayMicroseconds(20);
	digitalWrite(TRIG, LOW);

	while(digitalRead(ECHO) == LOW);
	long start_time = micros();
	while(digitalRead(ECHO) == HIGH);
	long elapsed_time = micros() - start_time;

	return elapsed_time / 58;
}

int main() {
	init();
	while(1){
		cout << “Distance: ” << get_distance() << endl;
		delay(100);
	}
	return 0;
}