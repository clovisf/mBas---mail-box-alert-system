/*
This code detects objects in from a a "line-finder" sensor and blinks a LED while the
object is present. I am testing it on a Teensy LC, but it should compile on Arduino UNO
as well.

This code is the base for a letter (mail) detection system.
Written by Clovis Fritzen (clovisf @ gmail DOT com) from "BlinkWithoutDelay" sketch.

*/

// LED on pin 17 to signalize that some movement was detected
const int ledPin =  17;      // the number of the LED pin
const int buttonPin = 2;
unsigned long time;
unsigned long previousTime;
boolean enterFunction= true;
boolean ledState;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);  
}

void loop()
{
  time = micros();
  if (enterFunction == true){
    previousTime= time;
    Serial.println(previousTime); // for debugging

    // Start your code below 
    //-----------------------

    ledState= digitalRead(buttonPin);
    if (ledState == LOW) {
      
    digitalWrite(ledPin, !digitalRead(ledPin));
    } else{
     
    }
    
    //-----------------------
    // End of your code
  }
  
  // The DELAY time is adjusted in the constant below >> 
  if (time - previousTime < 100000){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }
  
}

