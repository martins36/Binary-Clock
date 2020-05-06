#include <LedControlMS.h>
#include <GFRTC.h>

#define DIN 12
#define CS 10
#define CLK 11
#define NumMatrix 1

LedControl lc = LedControl(DIN, CLK, CS, NumMatrix);

void setup() {
  //Serial.begin(9600);
  GFRTC.begin(true);
  for (int i = 0; i < NumMatrix ; i++)
   {
       lc.shutdown(i, false); 
       lc.setIntensity(i, 8);
       lc.clearDisplay(i);
   }
}

void loop() {
  struct timelib_tm datetime;
  if (GFRTC.read(datetime)) {
    dec2bin(datetime.tm_hour, 4);
    //Serial.print(datetime.tm_hour);
    //Serial.print(":");
    dec2bin(datetime.tm_min, 2);
    //Serial.print(datetime.tm_min);
    //Serial.print(":");
    dec2bin(datetime.tm_sec, 0);
    //Serial.println(datetime.tm_sec);
  }
  delay(1000);
}

void dec2bin(int number, int i) {
  int x = number / 10;
  int y = number % 10;
  dec2led(x, i + 1);
  dec2led(y, i);
}

void dec2led(int digit, int i) {
  switch (digit) {
    case 1:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, false);
      lc.setLed(0, i, 6, false);
      lc.setLed(0, i, 7, true);
      break;
    case 2:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, false);
      lc.setLed(0, i, 6, true);
      lc.setLed(0, i, 7, false);
      break;
    case 3:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, false);
      lc.setLed(0, i, 6, true);
      lc.setLed(0, i, 7, true);
      break;
    case 4:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, true);
      lc.setLed(0, i, 6, false);
      lc.setLed(0, i, 7, false);
      break;
    case 5:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, true);
      lc.setLed(0, i, 6, false);
      lc.setLed(0, i, 7, true);
      break;
    case 6:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, true);
      lc.setLed(0, i, 6, true);
      lc.setLed(0, i, 7, false);
      break;
    case 7:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, true);
      lc.setLed(0, i, 6, true);
      lc.setLed(0, i, 7, true);
      break;
    case 8:
      lc.setLed(0, i, 4, true);
      lc.setLed(0, i, 5, false);
      lc.setLed(0, i, 6, false);
      lc.setLed(0, i, 7, false);
      break;
    case 9:
      lc.setLed(0, i, 4, true);
      lc.setLed(0, i, 5, false);
      lc.setLed(0, i, 6, false);
      lc.setLed(0, i, 7, true);
      break;
    default:
      lc.setLed(0, i, 4, false);
      lc.setLed(0, i, 5, false);
      lc.setLed(0, i, 6, false);
      lc.setLed(0, i, 7, false);
      break;
  }
}
