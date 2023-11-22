#include <UTFT.h>
#include <UTFT_DLB.h>
#include <UTFT_DDIG.h>

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
UTFT_DDIG myGLCD(SSD1963_800, 38, 39, 40, 41); //(byte model, int RS, int WR, int CS, int RST, int SER)

// Declare which fonts we will be using
//extern uint8_t SmallFont[];
//extern uint8_t BigFont[];
//extern uint8_t SevenSegment96x144Num[]; //SevenSegment96x144Num.c (To uncomment: Need to put this file in the same folder as sketch.ino)

void setup() {
  // put your setup code here, to run once:

  myGLCD.InitLCD();
  myGLCD.clrScr();

  Serial.begin(9600);

  myGLCD.clrScr();
}

void loop() {
  // put your main code here, to run repeatedly:

  //myGLCD.setFont(SevenSegment96x144Num); // (To uncomment: Need to put file SevenSegment96x144Num.c in the same folder as sketch.ino)

  unsigned long millis1;

  int i = 0, j;

  while (1)
  {
    // (To uncomment: Need to put file SevenSegment96x144Num.c in the same folder as sketch.ino)
    //
    //    myGLCD.setColor(VGA_RED);
    //
    //    j = 9;
    //    while (j--)
    //    {
    //      myGLCD.print(String(j), 0, 0); // update test
    //    }
    //
    //    millis1 = millis();
    //    myGLCD.print(String(i), 0, 0);
    //    millis1 = millis() - millis1;
    //    Serial.print("(ms) ttf96x144: ");
    //    Serial.print(millis1, DEC);
    //    Serial.print("  ");

    myGLCD.configDigit(96, 144, 10); //  Width, Height, Depth

    j = 9;
    while (j--)
    {
      myGLCD.drawDigit(j, 150, 0, VGA_GREEN, VGA_BLACK); // update test
    }

    millis1 = millis();
    myGLCD.drawDigit(i, 150, 0, VGA_GREEN, VGA_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 96x144: ");
    Serial.print(millis1, DEC);
    Serial.print("  ");

    myGLCD.configDigit(15, 30, 3); //  Width, Height, Depth

    j = 15;
    while (j--)
    {
      myGLCD.drawDigit(j, 300, 0, VGA_GREEN, VGA_BLACK); // update test
    }

    millis1 = millis();
    myGLCD.drawDigit(i, 300, 0, VGA_GREEN, VGA_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 15x30: ");
    Serial.print(millis1, DEC);
    Serial.print("  ");

    myGLCD.configDigit(200, 480, 30); //  Width, Height, Depth

    j = 9;
    while (j--)
    {
      myGLCD.drawDigit(j, 350, 0, VGA_GREEN, VGA_BLACK); // update test
    }

    millis1 = millis();
    myGLCD.drawDigit(i, 350, 0, VGA_GREEN, VGA_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 200x480: ");
    Serial.print(millis1, DEC);
    Serial.print("  ");

    myGLCD.configDigit(100, 300, 15); //  Width, Height, Depth

    j = 9;
    while (j--)
    {
      myGLCD.drawDigit(j, 600, 0, VGA_GREEN, VGA_BLACK); // update test
    }

    millis1 = millis();
    myGLCD.drawDigit(i, 600, 0, VGA_GREEN, VGA_BLACK);
    millis1 = millis() - millis1;
    Serial.print("DDIG 100x480: ");
    Serial.println(millis1, DEC);

    i++;
    if (i > 15) // SevenSegment96x144Num.c works only between 0-9
    {
      i = 0;
    }
  }
}
