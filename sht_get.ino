void sht_get(){
  sht.read();

  float temperature = sht.getTemperature();
  // Serial.println("---------------------------------------------");
  // Serial.print("Suhu : ");
  // Serial.print(temperature);
  // Serial.println("°C");
  sht_raw();
  Blynk.virtualWrite(V0, temperature);
  log_suhu = (temperature >= 30) ? 1 : 0;
  Blynk.virtualWrite(V53, log_suhu);
}

void sht_raw(){
  uint16_t rawTemperature;
  sht.requestData();
  rawTemperature = sht.getRawTemperature();
  
  byte msb = rawTemperature >> 8;
  byte lsb = rawTemperature & 0xFF;

  // Serial.print("MSB SHT31 : ");
  // Serial.print(msb,HEX);
  // Serial.print("\t LSB SHT31 : ");
  // Serial.println(lsb, HEX);
  // Serial.print("Combined Value SHT31-D : ");
  // Serial.println(rawTemperature);
  // Serial.print("Penghitungan SHT31-D : ");
  // Serial.print(rawTemperature * (175.0 / 65535) - 45, 2); 
  // Serial.println("°C\t");
  Blynk.virtualWrite(V46, rawTemperature);
}