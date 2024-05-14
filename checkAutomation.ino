BLYNK_WRITE(V12){
  pinvalueOtomatis = param.asInt();
}

void readSensor(){
  sht_get();
  bh_get();
  rain_get();
  limit_jemuran();
  kanopi();
}

void run(){
  if (stateMotor == 0){
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      readSensor();
      cekLogic();
    }
  }else if(stateMotor == 1){
    kanopi();
    delay(100);
  }
}

void checkAutomation(){
    run();
    if(pinvalueOtomatis == 1){
      controlrelayAuto();
      Blynk.setProperty(V11, "isHidden", true);
      staterelayOffManual = 0;
    }else{
      Blynk.setProperty(V11, "isHidden", false);
      kanopiManual();
    }
}

void cekLogic(){
  Serial.println("=================Table Logic=================");
  Serial.println("Log HUJAN  Log Cahaya  Log Suhu  Log Jemuran  Log Motor");
  Serial.println((String)log_rain+"\t"+log_cahaya+"\t"+log_suhu+"\t"+log_jemuran+"\t"+log_motor+"\t");
  Blynk.virtualWrite(V55, log_motor);
  // Serial.println("=============================================");
  // Serial.println("+++++++++++++++++++++++++++++++++++++++++++++");
}