//=====================Blynk IoT============================
#define BLYNK_TEMPLATE_ID           "TMPL6D7uYM_Kw"
#define BLYNK_TEMPLATE_NAME         "App Kanopy"
#define BLYNK_AUTH_TOKEN            "8L7gwvbGgowv5t8LnI7E5hYIFQ8WmtmX"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "8L7gwvbGgowv5t8LnI7E5hYIFQ8WmtmX";
char ssid[] = "Indihome Suharno";
char pass[] = "Damang@98";
const int   checkInterval = 1000;
unsigned long previousMillis = 0;
const long interval = 5000;
int status = WL_IDLE_STATUS;

//===========================================================
//==================D E F I N I T I O N======================
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <BH1750.h>
#include <RTClib.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <SHT31.h>


#define rainPowerPin 25
#define rainAnalogPin 33
#define jemuran_pin 32
#define kanopiOpen_pin 34
#define kanopiClose_Pin 35
#define relayOpen_pin 26
#define relayClose_pin 27

SHT31 sht(0x44);
BH1750 bh; 
RTC_DS3231 rtc;
BlynkTimer timer;

int log_motor;
int log_kanopi;
int log_suhu;
int log_jemuran;
int log_cahaya;
int log_rain;
int rainAnalog;
int staterelayOffManual = 0;
int pinvalueOtomatis, pinvalueManual, pinvalueKanopi;
int openK;
int closedK;
int stateMotor;

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

void setup() {
  Serial.begin(115200);
  cek_i2c(); 
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(rainPowerPin, OUTPUT);
  pinMode(jemuran_pin,INPUT);
  pinMode(kanopiOpen_pin,INPUT);
  pinMode(kanopiClose_Pin,INPUT);
  pinMode(relayOpen_pin,OUTPUT);
  pinMode(relayClose_pin,OUTPUT);
}

void loop() {
  Blynk.run();
  checkAutomation();
}