//#include <DMD3.h>
#include <Wire.h>
#include "RTClib.h"
#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include <DS3231.h>
#include "SystemFont5x7U.h"
#include "SystemFont5x7.h"
#include "WendyFont3x5.h"

#include <Arial14.h>
#include <Arial_black_16.h>
#include <Arial14.h>
//#include "Font_6x14.h" //-> This font only contains numbers from 0-9
#define DISPLAYS_ACROSS 1 //-> Number of P10 panels used, side to side.
#define DISPLAYS_DOWN 1
#define OE 9
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
RTC_DS1307 rtc;
 //Variable untuk kecerahan 
int x;

String textToScroll = "HAPPY BIRTHDAY TO RISHAV";
int _day, _month, _year, _hour12, _hour24, _minute, _second, _dtw;
int hr24;
String st;
int timeScroll = 150;
char month_name[12][12] = {"January", "February", "March", "April", "May", "June", "Jult", "August", "September", "October", "November", "December"};
char nameoftheday[7][12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
const long interval = 1000; //-> Retrieve time and date data every 1 second
unsigned long previousMillis = 0;
const long interval_for_date = 150; //-> For scroll speed
unsigned long previousMillis_for_date = 0;
char hr_24 [3];
String str_hr_24;
char mn [3];
String str_mn;
char sc [3];
String str_sc;

String strSecondRow;
char chrSecondRow[60];
void ScanDMD() {
  dmd.scanDisplayBySPI();

}


void setup() {
  Serial.begin(9600);
  Serial.println("Arduino RTC DS1307");
  delay(1000);
  Timer1.initialize( 2000 );
  dmd.clearScreen( true );
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");

    // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //   rtc.adjust(DateTime(2021, 2, 8, 8, 30, 0));
  }
  //        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //          rtc.adjust(DateTime(2021, 2, 11, 12, 02, 0));


  Timer1.initialize(1000);
   analogWrite(PIN_DMD_nOE, 200);
  Timer1.attachInterrupt(ScanDMD);
  dmd.clearScreen(true);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; //-> save the last time

    GetDateTime(); //-> Retrieve time and date data from DS1307

    dmd.selectFont(SystemFont5x7U);

    str_hr_24 = String(_hour24);
    str_hr_24.toCharArray(hr_24, 3);

    if (_hour24 < 10) {
      dmd.drawString(3, 0, "0", 1, GRAPHICS_NORMAL);
      dmd.drawString(9, 0, hr_24, 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(3, 0, hr_24, 2, GRAPHICS_NORMAL);
    }

    if (_second % 2 == 0) {
      dmd.drawFilledBox(15, 1, 16, 2, GRAPHICS_OR);
      dmd.drawFilledBox(15, 5, 16, 4, GRAPHICS_OR);
    }
    else {
      dmd.drawFilledBox(15, 1, 16, 2, GRAPHICS_NOR);
      dmd.drawFilledBox(15, 5, 16, 4, GRAPHICS_NOR);
    }


    str_mn = String(_minute);
    str_mn.toCharArray(mn, 3);

    if (_minute < 10) {
      dmd.drawString(18, 0, "0", 2, GRAPHICS_NORMAL);
      dmd.drawString(24, 0, mn, 2, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(18, 0, mn, 2, GRAPHICS_NORMAL);
    }
    GetDateTime();
    DateTime now = rtc.now();
    dmd.drawString( 0, 9, nameoftheday[_dtw], 3, GRAPHICS_NORMAL );
    if (hr24 > 12) {
      dmd.drawString(21, 9, "P", 1, GRAPHICS_NORMAL);
      dmd.drawString(27, 9, "M", 1, GRAPHICS_NORMAL);
    }
    else {
      dmd.drawString(21, 9, "A", 1, GRAPHICS_NORMAL);
      dmd.drawString(27, 9, "M", 1, GRAPHICS_NORMAL);
    }


    if (_second == 10) { //-> Display the date when seconds equal to 11
      if (_hour24 == 10 && _minute <= 10 && hr24 < 12) {
        while (1) {
          drawText1("GOOD MORNING");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }
      else if (_hour24 == 2 && _minute <= 10 && hr24 > 12) {
        while (1) {
          drawText1("GOOD AFTERNOON");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }
      else if (_hour24 == 7 && _minute <= 10 && hr24 > 12) {
        while (1) {
          drawText1("GOOD EVENING");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }
      else if (_hour24 == 10 && _minute <= 10 && hr24 > 12) {
        while (1) {
          drawText1("GOOD NIGHT");
          dmd.clearScreen(true);
          delay(0);
          return;
        }
      }

      else {

        scrolling_date();
      }
    }

  }
}
