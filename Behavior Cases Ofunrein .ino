#include <Servo.h>
Servo myservo;  // create servo object to control a servo


const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pinmmmmm
const int Flash =  7;       // flashing LED 
boolean start = false;
// variables will change:
volatile int toggleSwitch = 0;         // variable for reading the pushbutton status

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int led = 13;
int bluepin = 10;
int greenpin = 11;
int redpin = 9;
int soundpin = 12;

int rotate= 80;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  pinMode(Flash, OUTPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(0, pin_ISR, CHANGE);
  // attaches the servo on pin 9 to the servo object 
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(soundpin, OUTPUT);
   myservo.attach(9);  

}

void loop() {
  /*digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second*/
  /*int dialValue = analogRead(A0);
  int lightValue = map(dialValue, 0, 1023, 0, 255);
  lightValue = constrain(lightValue, 0, 185);
  int soundValue = map(dialValue, 0, 1023, 0, 100);
  soundValue = constrain(soundValue, 10, 100);
  Serial.println(lightValue);
  delay(1);

  digitalWrite(soundpin, HIGH);
  delayMicroseconds(soundValue);
  digitalWrite(soundpin, LOW);
  delayMicroseconds(soundValue);

  analogWrite(bluepin, 255-lightValue);  
  analogWrite(greenpin, lightValue); 
  analogWrite(redpin, 0); 
*/

	if (toggleSwitch == LOW){
	myservo.write(0);
	digitalWrite(led, LOW); 
	start = true;
	} 
	else if(start && toggleSwitch==HIGH){
        int randNumber = random(5); 
		Serial.println(randNumber);
		digitalWrite(led, HIGH);

		switch (randNumber)
	  {
	    case 0:
	 {   
	 	Serial.print("Case 0");
	 	myservo.write(40);
	 	delay(500);
	    myservo.write(60);
	    delay(500);
	    myservo.write(rotate);
	    start=false;
	 }    
	    break;
	    
	    case 1:
	{    
		Serial.print("Case 1");
	    myservo.write(rotate);
	    start=false;

	}    
	    break;
	    
	    case 2:
	{    
		Serial.print("Case 2");
	    myservo.write(rotate);
	    start=false;
	   
	}    
	    break;
	    
	    case 3:
	{    
		start=false;
		Serial.print("Case 3");
	    for(int i = 0; i<= rotate; i += 10) {
	    	myservo.write(i);
	    	delay(500);
	    }
	    myservo.write(0);
	    delay(1000);
	    myservo.write(80);
	}    
	    break;
	    
	    case 4:
	{    
		start=false;
		Serial.print("Case 4");
	    myservo.write(60);
	    delay(500);
	    myservo.write(100);
	}    
	    break;
	    
	    
	  }
	}
}

void pin_ISR() {
  toggleSwitch = digitalRead(buttonPin);
  digitalWrite(ledPin, toggleSwitch);
}