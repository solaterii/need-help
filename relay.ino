void relay() {
  Serial.println("Logika Motor : " + String(log_motor) + " Logika Kanopi : " + String(log_kanopi));
}

void operateRelayBlynk(const String& statusRelay, int setpinOpen, int setpinClose, int blynkValue, int virtualPin) {
  digitalWrite(relayOpen_pin, setpinOpen);
  digitalWrite(relayClose_pin, setpinClose);
  Blynk.virtualWrite(virtualPin, blynkValue);
  // Serial.println("Kanopi" + statusRelay);
  // Serial.println("Jalan Auto");
}

void controlrelayAuto(){
  // logic_kanopi();
    if (log_motor == 0 && log_kanopi == 1) {//Opening
    operateRelayBlynk("Bergerak Membuka",HIGH, LOW, 1, V2);
    } else if (log_motor == 1 && log_kanopi == 0) {//Closing
    operateRelayBlynk("Bergerak Menutup",LOW, HIGH, 1, V2);
    }  else if (log_motor == 0 && log_kanopi == 0) {//Openend
    operateRelayBlynk("Sudah Terbuka",LOW, LOW, 0, V2);
    } else if (log_motor == 1 && log_kanopi == 1) {//Closed
    operateRelayBlynk("Sudah Tertutup",LOW, LOW, 0, V2);
    }
}

void controlrelayOpen(int kanopi){
  if (kanopi == 1) {
    operateRelayBlynk("Bergerak Membuka",HIGH, LOW, 1, V2);
  }else if (kanopi == 0) {
    operateRelayBlynk("Sudah Terbuka", LOW, LOW, 0, V2);
  }else if (log_kanopi == 2){
    operateRelayBlynk("Bergerak Membuka",HIGH, LOW, 1, V2);
  }
  // Serial.println("Jalan Manual");
}

void controlrelayClose(int kanopi){
  if (kanopi == 1) {
    operateRelayBlynk("Sudah Tertutup", LOW, LOW, 0, V2);
  }else if (kanopi == 0) {
    operateRelayBlynk("Bergerak Menutup", LOW, HIGH, 1, V2);
  }else if (log_kanopi == 2){
    operateRelayBlynk("Bergerak Menutup",LOW, HIGH, 1, V2);
  }
  // Serial.println("Jalan Manual");
}

void controlrelayOff(){
  operateRelayBlynk("Berhenti ",LOW, LOW, 0, V2);
}
