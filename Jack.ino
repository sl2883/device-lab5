/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;     // the number of the pushbutton pin
const int buttonPin3 = 4;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;         // variable for reading the pushbutton status


  bool prevLowState1 = true;
  bool prevLowState2 = true;
  bool prevLowState3 = true;
  
int currentPos = 0;

/*************************************************
 * Public Constants
 *************************************************/

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978



int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int melody1[] = {
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 4, 4, 4, 4, 4, 4, 4
};

int password[6] = {1,2,3,1,2,3};

void setup() {
  Serial.begin(9600);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop() {
  
  int currentInput = 0;
  bool button1Pressed = false;
  bool button2Pressed = false;
  bool button3Pressed = false;
 
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    if(prevLowState1) {
      currentInput = 1;
      // turn LED on:
      digitalWrite(ledPin, HIGH);
      button1Pressed = true;
      prevLowState1 = false;
    }
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    button1Pressed = false;
    prevLowState1 = true;
  }

  if(!button1Pressed) {
      buttonState2 = digitalRead(buttonPin2);
      
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState2 == HIGH) {
      if(prevLowState2) {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
        currentInput = 2;
        button2Pressed = true;
        prevLowState2 = false;
      }
    } else {
      // turn LED off:
      digitalWrite(ledPin, LOW);
      button2Pressed = false;
      prevLowState2 = true;
    }
  }

  if(!button1Pressed && !button2Pressed) {
      buttonState3 = digitalRead(buttonPin3);
  
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState3 == HIGH) {
      if(prevLowState3) {
        // turn LED on:
        digitalWrite(ledPin, HIGH);
        currentInput = 3;
        button3Pressed = true;
        prevLowState3 = false;
      }
    } else {
      // turn LED off:
      digitalWrite(ledPin, LOW);
      button3Pressed = false;
      prevLowState3 = true;
    }
  }

  if(button1Pressed || button2Pressed || button3Pressed) {
    Serial.println("Position " + String(currentPos));
    Serial.println("Input " + String(currentInput));
    Serial.println("Expected " + String(password[currentPos]));
    if(password[currentPos] == currentInput) {
      if(currentPos == 5) {
        Serial.println("Password found");
        for (int thisNote = 0; thisNote < 8; thisNote++) {

          // to calculate the note duration, take one second divided by the note type.
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(8, melody[thisNote], noteDuration);
      
          // to distinguish the notes, set a minimum time between them.
          // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          // stop the tone playing:
          noTone(8);
        }
        
        for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15ms for the servo to reach the position
        }
        
        delay(1000);
        
        for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(0);                       // waits 15ms for the servo to reach the position
        }

        for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15ms for the servo to reach the position
        }
        
        delay(1000);
        
        for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(0);                       // waits 15ms for the servo to reach the position
        }

        for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(10);                       // waits 15ms for the servo to reach the position
        }
        
        delay(1000);
        
        for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(0);                       // waits 15ms for the servo to reach the position
        }
        currentPos = 0;
      }
      else {
        currentPos++;
      }
    }
    else {
      Serial.println("Failed");
      for (int thisNote = 0; thisNote < 8; thisNote++) {
    
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations1[thisNote];
        tone(8, melody1[thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          
        // stop the tone playing:
        noTone(8);
      }
      currentPos = 0;
    }
  }
}
