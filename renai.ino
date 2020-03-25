/*
  Melody

  Plays Ren'ai Circulation

  circuit:
  - Piezo buzzer on pin 8

  created 21 Jan 2010
  modified 24 Mar 2020
  by Shinyo

  Based on the example code on
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

int buzzerPin = 8;
// notes in the melody:
int melody[] = {
    NOTE_G4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_G4, 0,
    NOTE_G4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_B4, 0,
    NOTE_G4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4,
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_B4, 0,
    
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_G4, 0,
    NOTE_D4, NOTE_E4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_G4, 0,
    NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, 0,
    NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, 0,
    NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_E4, NOTE_B4, 0,
    
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_G4, 0,
    NOTE_D4, NOTE_E4,
    NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_G4, 0,
    NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, 0,
    NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, 0,
    NOTE_G4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_A4, NOTE_G4, 0,
    
    NOTE_D5, NOTE_B4, NOTE_A4, NOTE_B4,
    NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, 0,
    
    NOTE_B4, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_G4, 
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, 0,
    
    NOTE_D5, NOTE_B4, NOTE_A4, NOTE_B4,
    NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, 0,
    
    NOTE_B4, NOTE_E5, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_G4, 0
    
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = 
{
    8, 8, 3, 3, 6, 3, 6, 6,
    8, 8, 3, 3, 6, 3, 6, 6,
    8, 8, 3, 3, 6, 3, 6, 8, 4,
    3, 6, 8, 6, 6, 1.5, 
    
    3, 3, 8, 10, 3, 6, 8,
    8, 8,
    3, 3, 8, 10, 3, 6, 6,
    6, 5, 8, 6, 6,
    6, 5, 8, 6, 6,
    4, 8, 6, 3, 5, 3, 2,
    
    3, 3, 8, 10, 3, 6, 8,
    8, 8,
    3, 3, 8, 10, 3, 6, 6,
    6, 5, 8, 6, 6,
    6, 5, 8, 6, 6,
    4, 8, 6, 3, 5, 3, 2,
    
    2.5, 2.5, 2.5, 2.5,
    5, 6, 5, 1.5, 16, 
    
    5, 2.5, 2.5, 2.5, 2.5,
    5, 6, 5, 1, 8,
    
    2.5, 2.5, 2.5, 2.5,
    5, 6, 5, 1.5, 16,
    
    4, 2.5, 2.5, 2.5, 2.5, 2.5, 1, 2
    
};

int size = sizeof(melody) / sizeof(int);

void setup() 
{
}

void loop() 
{
  song();
}

void song()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < size; thisNote++) {
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000.0 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
}
