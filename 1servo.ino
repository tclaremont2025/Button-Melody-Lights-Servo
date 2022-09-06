#include <Servo.h>
#include "pitches.h"

const int buzzerPin = 2;
const int buttonPin = 3;     // the number of the pushbutton pin
const int ledgreen =  12;      // the number of the LED pin
const int ledred = 11;
const int ledblue = 10;
const int ledwhite = 9;
const int ledgreen2 = 8;
const int ledred2 = 7;
const int ledblue2 = 6;
const int ledwhite2 = 5;
const int ledamber = 4;
Servo myServo;
int buttonState = 0;

// notes in the melody:
// use 0 for a rest
// put each measure on its own line
int melody[] = {
  NOTE_C3, NOTE_G3, 0, NOTE_G3, NOTE_C3, 0, 
  NOTE_D3, NOTE_A3, 0, NOTE_A3, NOTE_D3, 0,
  NOTE_E3, NOTE_B3, 0, NOTE_B3, NOTE_E3, 0,
  NOTE_F3, NOTE_C4, 0, NOTE_C4, NOTE_F3, 0,
  NOTE_G3, NOTE_D4, 0, NOTE_D4, NOTE_G3, 0,
  NOTE_A3, NOTE_E4, 0, NOTE_E4, NOTE_A3, 0,
  NOTE_B3, NOTE_FS4, 0, NOTE_FS4, NOTE_B3, 0,
  NOTE_C4, NOTE_G4, 0, NOTE_G4, NOTE_C4, 0, 
  NOTE_D4, NOTE_A4, 0, NOTE_A4, NOTE_D4, 0,
  NOTE_E4, NOTE_B4, 0, NOTE_B4, NOTE_E4, 0,
  NOTE_F4, NOTE_C5, 0, NOTE_C5, NOTE_F4, 0,
  NOTE_G4, NOTE_D5, 0, NOTE_D5, NOTE_G4, 0,
  NOTE_A4, NOTE_E5, 0, NOTE_E5, NOTE_A4, 0,
  NOTE_B4, NOTE_FS5, 0, NOTE_FS5, NOTE_B4, 0,
  
};

// note durations: 1 = whole note, 4 = quarter note, 8 = eighth note, etc.:
// be sure each note or rest in the melody above has a corresponding duration below
// put each measure on its own line
int noteDurations[] = {
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
  2, 4, 6, 4, 2, 2,
};

// set the tempo
// a tempo of 60 is one beat per second
// a tempo of 120 would be twice as fast
int beatsPerMinute = 60;
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(13);
   // initialize the LED pin as an output:
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(ledwhite, OUTPUT);
  pinMode(ledgreen2, OUTPUT);
  pinMode(ledred2, OUTPUT);
  pinMode(ledblue2, OUTPUT);
  pinMode(ledwhite2, OUTPUT);
  pinMode(ledamber, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
  myServo.write(180);
  delay(1000);
  myServo.write(0);
  delay(1000);
  playSong();
  christmasLightSequenceON();
  }
  if (buttonState == LOW) {
  christmasLightSequenceOFF();
  }
}

void playSong() {
   // iterate over the notes of the melody:
  int len = sizeof(melody)/sizeof(melody[0]);
  for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(1000);
}

void christmasLightSequenceON() {
    // turn LED on:
    digitalWrite(ledgreen, HIGH);
    delay(500);
    digitalWrite(ledred, HIGH);
    delay(500);
    digitalWrite(ledblue, HIGH);
    delay(500);
    digitalWrite(ledwhite, HIGH);
    delay(500);
    digitalWrite(ledgreen2, HIGH);
    delay(500);
    digitalWrite(ledred2, HIGH);
    delay(500);
    digitalWrite(ledblue2, HIGH);
    delay(500);
    digitalWrite(ledwhite2, HIGH);
    delay(500);
    digitalWrite(ledgreen, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(ledamber, HIGH);
    delay(500);

    
  digitalWrite(ledgreen, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(ledgreen2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
  digitalWrite(ledred2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(ledgreen2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(ledamber, HIGH);
  delay(250);
  digitalWrite(ledamber, LOW);
  delay(250);
  digitalWrite(ledamber, LOW);
  delay(250);

  digitalWrite(ledgreen, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledgreen, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(ledgreen2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  digitalWrite(ledred2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(ledgreen2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(ledamber, HIGH);
  delay(100);
  digitalWrite(ledamber, LOW);
  delay(100);
  digitalWrite(ledamber, LOW);
  delay(100); 


  digitalWrite(ledwhite, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledwhite, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(ledwhite2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
  digitalWrite(ledred2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(ledwhite2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  delay(250);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(250); 

      digitalWrite(ledwhite, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledwhite, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(ledwhite2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  digitalWrite(ledred2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(ledwhite2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledred, LOW);    // turn the LED off by making the voltage LOW
  delay(100); 


  digitalWrite(ledwhite, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, HIGH);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, HIGH);
  delay(1000);
  digitalWrite(ledwhite, LOW);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, LOW);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, LOW);
  delay(1000);

digitalWrite(ledwhite, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, HIGH);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, HIGH);
  delay(1000);
  digitalWrite(ledwhite, LOW);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, LOW);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, LOW);
  delay(1000);

  digitalWrite(ledwhite, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, HIGH);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, HIGH);
  delay(1000);
  digitalWrite(ledwhite, LOW);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, LOW);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, LOW);
  delay(1000);

  digitalWrite(ledwhite, HIGH);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, HIGH);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, HIGH);
  delay(1000);
  digitalWrite(ledwhite, LOW);   // turn the LED on (HIGH is the voltage level)                      // wait for a second
  digitalWrite(ledwhite2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledred, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledred2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledgreen, LOW);   // turn the LED on (HIGH is the voltage level                    // wait for a second
  digitalWrite(ledgreen2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledblue, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledblue2, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(ledamber, LOW);
  delay(1000);
  }

 void christmasLightSequenceOFF() {
 digitalWrite(ledgreen, LOW);
    delay(500);
    digitalWrite(ledred, LOW);
    delay(500);
    digitalWrite(ledblue, LOW);
    delay(500);
    digitalWrite(ledwhite, LOW);
    delay(500);
    digitalWrite(ledgreen2, LOW);
    delay(500);
    digitalWrite(ledred2, LOW);
    delay(500);
    digitalWrite(ledblue2, LOW);
    delay(500);
    digitalWrite(ledwhite2, LOW);
    delay(500);
    digitalWrite(ledamber, LOW);
    delay(500);
    digitalWrite(ledgreen, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    
  }

 
 
