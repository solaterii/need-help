void kanopi() {
  openK = digitalRead(kanopiOpen_pin);
  closedK = digitalRead(kanopiClose_Pin);
  // Serial.println((String)"Limit Buka = "+openK);
  // Serial.println((String)"Limit Tutup = "+closedK);

  if (openK == 1 && closedK == 0) {
    checkKanopi("kanopi_tertutup", 1);
  } else if (openK == 0 && closedK == 1) {
    checkKanopi("kanopi_terbuka", 0);
  } else if (openK == 1 && closedK == 1) {
    if(staterelayOffManual == 1){
     checkKanopi("kanopi_berhenti", 4);
    }else{checkKanopi("bergerak", 2);}
  } else{
    checkKanopi("kanopi_error", 3);
  }
}

void checkKanopi(const String& event, int data_log){
  // Serial.println("---------------------------------------------");
  // Serial.println("Kanopi " + event);
  log_kanopi = data_log;
  Blynk.virtualWrite(V4, data_log);
  Blynk.logEvent(event);
}
