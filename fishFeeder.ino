#include <Servo.h>
#include <Time.h>
#include "TimeAlarms.h"
//THESE ARE REQUIRED PLEASE DOWNLOAD AND STORE IN DIRECTORY OF THIS PROGRAM
//time libraries have been used from https://github.com/PaulStoffregen/Time 
//"time alarms library" from https://github.com/PaulStoffregen/TimeAlarms

Servo myservo;  // create servo object to control a servo


int pos = 0;    // variable to store the servo position

void setup() {
	Serial.begin(9600); //init serial connection at 9600 baud
	setTime(7, 59, 45, 3, 5, 17); //set the time to 12:55:00 3/5/2017
	
	Alarm.alarmRepeat(8,0,0,feedAlarm); //alarm to feed fish goes off at 8am
	// Alarm.alarmRepeat(8,0,30,feedAlarm);  //uncomment these to test on 30 second intervals 3 times
	// Alarm.alarmRepeat(8,1,0,feedAlarm);
	Alarm.alarmRepeat(12,0,0,feedAlarm);//alarm set for 12pm
	Alarm.alarmRepeat(16,0,0,feedAlarm);//alarm set for 4pm
	myservo.attach(10);  // attaches the servo on pin 10 to the servo object
	myservo.write(0);
	
}

void loop() {
	
	digitalClockDisplay();
	Alarm.delay(1000);

}


void digitalClockDisplay()
{
	// digital clock display of the time
	Serial.println(pos);
	Serial.print(hour());
	printDigits(minute());
	printDigits(second());
	Serial.println();
}
void printDigits(int digits)
{
	Serial.print(":");
	if (digits < 10)
		Serial.print('0');
	Serial.print(digits);
}

//moves servo to correct position
//wait 3 seconds
//move back to upright position 
void feedAlarm(){

	myservo.write(180);
	delay(3000);
	myservo.write(0);
	

	

}