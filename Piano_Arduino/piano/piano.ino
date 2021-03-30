#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

#include <avr/pgmspace.h>
#include <LiquidCrystal.h>

int note_C[8] = {NOTE_C1, NOTE_C2, NOTE_C3, NOTE_C4, NOTE_C5, NOTE_C6, NOTE_C7, NOTE_C8};
int note_CS[7] = {NOTE_C1, NOTE_CS2, NOTE_CS3, NOTE_CS4, NOTE_CS5, NOTE_CS6, NOTE_CS7};
int note_D[7] = {NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6, NOTE_D7};
int note_DS[7] = {NOTE_DS1, NOTE_DS2, NOTE_DS3, NOTE_DS4, NOTE_DS5, NOTE_DS6, NOTE_DS7};
int note_E[7] = {NOTE_E1, NOTE_E2, NOTE_E3, NOTE_E4, NOTE_E5, NOTE_E6, NOTE_E7};
int note_F[7] = {NOTE_F1, NOTE_F2, NOTE_F3, NOTE_F4, NOTE_F5, NOTE_F6, NOTE_F7};
int note_FS[7] = {NOTE_FS1, NOTE_FS2, NOTE_FS3, NOTE_FS4, NOTE_FS5, NOTE_FS6, NOTE_FS7};
int note_G[7] = {NOTE_G1, NOTE_G2, NOTE_G3, NOTE_G4, NOTE_G5, NOTE_G6, NOTE_G7};
int note_GS[7] = {NOTE_GS1, NOTE_GS2, NOTE_GS3, NOTE_GS4, NOTE_GS5, NOTE_GS6, NOTE_GS7};
int note_A[7] = {NOTE_A1, NOTE_A2, NOTE_A3, NOTE_A4, NOTE_A5, NOTE_A6, NOTE_A7};
int note_AS[7] = {NOTE_AS1, NOTE_AS2, NOTE_AS3, NOTE_AS4, NOTE_AS5, NOTE_AS6, NOTE_AS7};
int note_B[7] = {NOTE_B1, NOTE_B2, NOTE_B3, NOTE_B4, NOTE_B5, NOTE_B6, NOTE_B7};

int nbOfSongs = 5;
int songSize  = 45;

int melodies[][45] = {
  {NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_C4,
   NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_D4, 0, 0, 0, 0},
  {NOTE_A4, NOTE_A4, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5,       0, NOTE_A4, NOTE_A4, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5,
   NOTE_A4, NOTE_A4, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_E5,       0, NOTE_C5, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, 0, 0},
  {NOTE_AS5, 0, 0, NOTE_A5, 0, NOTE_G5, 0, NOTE_AS4, 0, NOTE_AS5, 0, 0, NOTE_A5, 0, NOTE_G5, NOTE_G5, NOTE_G5,
   NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5},
  {NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
   NOTE_F4, NOTE_F4,       0, NOTE_F4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_C5},
  {      0, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_FS4, NOTE_E4, 0, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_A4,
   NOTE_GS4, NOTE_GS4, 0, 0, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_E4, NOTE_E4,
   NOTE_E4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_E4, NOTE_E4, NOTE_GS4, NOTE_GS4, NOTE_GS4, 0, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4,
   NOTE_GS4, NOTE_E4}
};

float durations[][45] = {
  {1, 1, 1, 0.5, 0.5, 0.75, 0.75, 0.25, 0.75, 0.25, 0.5, 0.5,
   1, 1, 1, 0.5, 0.5, 0.75, 0.75, 0.25, 0.75, 0.75, 0.5, 1, 1, 1, 1, 1},
  {1, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5,
   1, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1}, 
  {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 2.5, 2, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
   0.5, 0.5, 0.5, 1, 1.5, 0.5, 0.5, 0.5, 1, 0.5},
  {0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 2.5, 0.5, 0.5, 1, 
   0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1.5, 0.5, 1, 2.5},
  {0.5, 0.5, 0.5, 0.5, 1, 1, 0.5, 1, 2.5, 1, 1, 1, 0.5, 1, 0.5, 1.5, 1, 0.5, 0.5, 1, 1, 0.5, 0.5,
   0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5, 1, 0.5, 1, 1, 0.5, 1.5, 1, 2, 1, 1, 3.5, 1, 3.5}
};

int tempos [5] = { 120, 120, 94, 158, 175};

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {  
  pinMode(29, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  pinMode(43, INPUT_PULLUP);
  pinMode(45, INPUT_PULLUP);
  pinMode(47, INPUT_PULLUP);
  pinMode(49, INPUT_PULLUP);
  pinMode(51, INPUT_PULLUP);
  pinMode(53, INPUT_PULLUP);
  pinMode( 2, OUTPUT);

  lcd.begin(16, 2);
  
  Serial.begin(9600);

  pinMode(50, INPUT_PULLUP); //play

  Serial.begin (9600);  
}

void loop() {  
  int val  = analogRead(A0); //octave
  int val2 = analogRead(A1); //autoplay
  int valNote = map(val , 0, 1000, 0, 6);
  int valSong = map(val2, 0, 1000, 0, nbOfSongs - 1);

  lcd.setCursor(0,0);
  lcd.print("Octave:");
  lcd.print(valNote + 1);

  lcd.setCursor(13,0);
  lcd.print("P:");
  lcd.print(valSong + 1);

  lcd.setCursor(0,1);
  lcd.print("Song:Not Playing");

  if (digitalRead(50) == LOW) {
    lcd.setCursor(5,1);
    lcd.print("           ");
    lcd.setCursor(5,1);
    lcd.print(valSong + 1);
    for(int i = -1; i < songSize; i++) {
      if (valSong == 2 && i < 17) {
        float duration = 60000 / tempos[valSong] * durations[valSong][i];
        tone( 2, melodies[valSong][i], duration);
        Serial.print(duration);
        Serial.print("\n");
        delay(duration);
      } else if (valSong == 2 && i > 17) {
        float duration = 60000 / 158 * durations[valSong][i];
        tone( 2, melodies[valSong][i], duration);
        delay(duration);
      } else {
        tone( 2, melodies[valSong][i], (60000/(tempos[valSong])) * durations[valSong][i]);
        delay((60000/(tempos[valSong])) * durations[valSong][i]);
      }
    }
  }
  
  if (digitalRead(53) == LOW) {
    tone( 2, note_C[valNote], 100);
    Serial.print("here");
  }
  if (digitalRead(51) == LOW) {
    tone( 2, note_CS[valNote], 100);
  }
  if (digitalRead(49) == LOW) {
    tone( 2, note_D[valNote], 100);
  }
  if (digitalRead(47) == LOW) {
    tone( 2, note_DS[valNote], 100);
  }
  if (digitalRead(45) == LOW) {
    tone( 2, note_E[valNote], 100);
  }
  if (digitalRead(43) == LOW) {
    tone( 2, note_F[valNote], 100);
  }
  if (digitalRead(41) == LOW) {
    tone( 2, note_FS[valNote], 100);
  }
  if (digitalRead(39) == LOW) {
    tone( 2, note_G[valNote], 100);
  }
  if (digitalRead(37) == LOW) {
    tone( 2, note_GS[valNote], 100);
  }
  if (digitalRead(35) == LOW) {
    tone( 2, note_A[valNote], 100);
  }
  if (digitalRead(33) == LOW) {
    tone( 2, note_AS[valNote], 100);
  }
  if (digitalRead(31) == LOW) {
    tone( 2, note_B[valNote], 100);
  }
  if (digitalRead(29) == LOW) {
    tone( 2, note_C[valNote + 1], 100);
  }
  delay(10);
}
