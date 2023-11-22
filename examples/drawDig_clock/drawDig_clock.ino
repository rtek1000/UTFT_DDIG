// Date and time functions using just software, based on millis() & timer
// Need RTClib (by Adafruit) https://github.com/adafruit/RTClib or 
// You can add/install RTClib: Sketch > Include lbrary > Manage library > "Filter your search" > Type: RTClib) 

#include <UTFT.h>
#include <UTFT_DLB.h>
#include <UTFT_DDIG.h>
#include <TimeLib.h>
#include <Wire.h>         // this #include still required because the RTClib depends on it
#include "RTClib.h"

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
UTFT_DDIG myGLCD(SSD1963_800, 38, 39, 40, 41); //(byte model, int RS, int WR, int CS, int RST, int SER)

RTC_Millis rtc;

int second_old = 0, disp_d10 = 0, disp_d1 = 0, disp_u1 = 0, disp_u10 = 0;
bool blink_point;

void setup() {
  // put your setup code here, to run once:

  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));

  myGLCD.InitLCD();
  myGLCD.clrScr();

  Serial.begin(9600);

  myGLCD.clrScr();

  myGLCD.fillCircle(400, 160, 10);
  myGLCD.fillCircle(400, 320, 10);

  myGLCD.setColor(VGA_GREEN);
  myGLCD.configDigit(162, 480, 30); //  Width, Height, Depth

  DateTime now = rtc.now();

  disp_u1 = now.second() - ((now.second() / 10) * 10);
  disp_u10 = now.second() / 10;
  disp_d1 = now.minute() - ((now.minute() / 10) * 10);
  disp_d10 = now.minute() / 10;

  myGLCD.drawDigit(disp_u1, 638, 0, VGA_GREEN, VGA_BLACK); // update test
  myGLCD.drawDigit(disp_u10, 426, 0, VGA_GREEN, VGA_BLACK); // update test
  myGLCD.drawDigit(disp_d1, 214, 0, VGA_GREEN, VGA_BLACK); // update test
  myGLCD.drawDigit(disp_d10, 0, 0, VGA_GREEN, VGA_BLACK); // update test
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();

  if (second_old != now.second())
  {
    second_old = now.second();

    disp_u1 = now.minute() - ((now.minute() / 10) * 10);
    myGLCD.drawDigit(disp_u1, 638, 0, VGA_GREEN, VGA_BLACK); // update test

    if (disp_u10 != (now.minute() / 10))
    {
      disp_u10 = now.minute() / 10;
      myGLCD.drawDigit(disp_u10, 426, 0, VGA_GREEN, VGA_BLACK); // update test
      if (disp_d1 != (now.hour() - ((now.hour() / 10) * 10)))
      {
        disp_d1 = now.hour() - ((now.hour() / 10) * 10);
        myGLCD.drawDigit(disp_d1, 214, 0, VGA_GREEN, VGA_BLACK); // update test
        if (disp_d10 != (now.hour() / 10))
        {
          disp_d10 = now.hour() / 10;
          myGLCD.drawDigit(disp_d10, 0, 0, VGA_GREEN, VGA_BLACK); // update test
        }
      }
    }

    if (blink_point)
    {
      blink_point = false;

      myGLCD.setColor(VGA_BLACK);
      myGLCD.fillCircle(400, 160, 10);
      myGLCD.fillCircle(400, 320, 10);
      myGLCD.setColor(VGA_GREEN);
      myGLCD.drawCircle(400, 160, 10);
      myGLCD.drawCircle(400, 320, 10);
    }
    else
    {
      blink_point = true;
      myGLCD.setColor(VGA_GREEN);
      myGLCD.fillCircle(400, 160, 10);
      myGLCD.fillCircle(400, 320, 10);
    }
  }
}
