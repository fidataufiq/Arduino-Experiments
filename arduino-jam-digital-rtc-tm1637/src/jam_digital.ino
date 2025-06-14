#include <Wire.h>
#include <RTClib.h>
#include <TM1637Display.h>

// -------- PIN DEFINISI --------
#define PIN_TM_CLK   8
#define PIN_TM_DIO   9

// -------- PIN 3 BTN UNTUK 3 PENGATURAN --------
#define PIN_BTN_H    2   //+jam
#define PIN_BTN_M    3   //+menit
#define PIN_BTN_B    4   // kecerahan

// -------- OBJEK LIBRARY --------
RTC_DS1307 rtc;
TM1637Display display(PIN_TM_CLK, PIN_TM_DIO);

// -------- VARIABEL --------
int brightnessLevel = 4;      // Default brightness (0 - 7)
bool prevBtnH = HIGH;
bool prevBtnM = HIGH;
bool prevBtnB = HIGH;

// --------- FUNGSI TAMPILAN JAM ---------
void showTime() {
  DateTime now = rtc.now();
  int hours = now.hour();
  int minutes = now.minute();

  int displayValue = hours * 100 + minutes;
  display.showNumberDecEx(displayValue, 0b01000000, true); // tampil JAM:MENIT
}

// --------- HANDLE TOMBOL ---------
void handleButtons() {
  bool curH = digitalRead(PIN_BTN_H);
  bool curM = digitalRead(PIN_BTN_M);
  bool curB = digitalRead(PIN_BTN_B);

  if (prevBtnH == HIGH && curH == LOW) {
    DateTime now = rtc.now();
    rtc.adjust(now + TimeSpan(3600));  // + 1 jam
  }

  if (prevBtnM == HIGH && curM == LOW) {
    DateTime now = rtc.now();
    rtc.adjust(now + TimeSpan(60));   // + 1 menit
  }

  if (prevBtnB == HIGH && curB == LOW) {
    brightnessLevel++;
    if (brightnessLevel > 7) brightnessLevel = 0;
    display.setBrightness(brightnessLevel);
  }

  prevBtnH = curH;
  prevBtnM = curM;
  prevBtnB = curB;
}

// --------- SETUP ---------
void setup() {
  pinMode(PIN_BTN_H, INPUT_PULLUP);
  pinMode(PIN_BTN_M, INPUT_PULLUP);
  pinMode(PIN_BTN_B, INPUT_PULLUP);

  Wire.begin();
  rtc.begin();

  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  display.setBrightness(brightnessLevel);
}

// --------- LOOP ---------
void loop() {
  handleButtons();
  showTime();
  delay(200); // untuk debounce dan refresh display
}
