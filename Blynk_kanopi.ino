//=====================Blynk IoT============================
#define BLYNK_TEMPLATE_ID           ""
#define BLYNK_TEMPLATE_NAME         ""
#define BLYNK_AUTH_TOKEN            ""

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "";
const char* ssid = "";
const char* pass = "";
const int   checkInterval = 1000;
int status = WL_IDLE_STATUS;

//===========================================================
//==================D E F I N I T I O N======================
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <BH1750.h>
#include <RTClib.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include "SHT31.h"


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
int pinvalueOtomatis,pinvalueManual, pinvalueKanopi;
int openK;
int closedK;
char status_wifi;
//======================F U N C T I O N======================
void sendSensor()
{
  sht_get();
  bh_get();
  rain_get();
  limit_jemuran();
  logic_kanopi();
  cekLogic();
}

void runRelay(){
  kanopi();
  checkAutomation();
}

void blynkCheck() {
  Serial.println("---------------------------------------------");
  Serial.println("JALAN BlynkCheck");
  Serial.print((String)WiFi.status()+"\t");
  if (WiFi.status() == 3) {
    if(!Blynk.connected()){
      char* connectingToBlynk = "WiFi OK, try CONNECTING to the Blynk server...";
      Serial.println(connectingToBlynk);
      Blynk.connect(checkInterval);
    }else{
      char* connectedToBlynk = "WiFi OK, CONNECTED to the Blynk server...";
      Serial.println(connectedToBlynk);
    }
  }
}


void runWifi() {
  WiFi.begin(ssid, pass);
  int tryDelay = 100;
  int numberOfTries = 50;

  while (true) {    
      switch(WiFi.status()) {
        case WL_NO_SSID_AVAIL:
          Serial.println("[WiFi] SSID not found");
          break;
        case WL_CONNECT_FAILED:
          Serial.print("[WiFi] Failed - WiFi not connected! Reason: ");
          return;
          break;
        case WL_CONNECTION_LOST:
          Serial.println("[WiFi] Connection was lost");
          break;
        case WL_SCAN_COMPLETED:
          Serial.println("[WiFi] Scan is completed");
          break;
        case WL_DISCONNECTED:
          Serial.println("[WiFi] WiFi is disconnected");
          break;
        case WL_CONNECTED:
          Serial.println("[WiFi] WiFi is connected!");
          Serial.print("[WiFi] IP address: ");
          Serial.println(WiFi.localIP());
          return;
          break;
        default:
          Serial.print("[WiFi] WiFi Status: ");
          Serial.println(WiFi.status());
          break;
      }
      delay(tryDelay);
      if(numberOfTries <= 0){
        Serial.print("[WiFi] Failed to connect to WiFi!");
        WiFi.disconnect();
        return;
      } else {
        numberOfTries--;
      }
  }
}

BLYNK_CONNECTED() {
   Blynk.syncAll();
}

void setup() {
  Serial.begin(115200);
  cek_i2c(); 
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  runWifi();
  Blynk.config(auth);

  pinMode(rainPowerPin, OUTPUT);
  pinMode(jemuran_pin,INPUT);
  pinMode(kanopiOpen_pin,INPUT);
  pinMode(kanopiClose_Pin,INPUT);
  pinMode(relayOpen_pin,OUTPUT);
  pinMode(relayClose_pin,OUTPUT);

  timer.setInterval(500L, runRelay);
  timer.setInterval(checkInterval, blynkCheck);
}

void loop() {
  Blynk.run();
  timer.run();
  sendSensor();
  delay(checkInterval);
}
//==================================================
void cekLogic(){
  Serial.println("=================Table Logic=================");
  Serial.println("Log HUJAN  Log Cahaya  Log Suhu  Log Jemuran  Log Motor");
  Serial.println((String)log_rain+"\t"+log_cahaya+"\t"+log_suhu+"\t"+log_jemuran+"\t"+log_motor+"\t");
  Blynk.virtualWrite(V55, log_motor);
  // Serial.println("=============================================");
  // Serial.println("+++++++++++++++++++++++++++++++++++++++++++++");
}
