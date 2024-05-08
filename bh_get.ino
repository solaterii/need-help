void bh_get() {

  float light_level = bh.readLightLevel();
  float raw_level = bh.readRawLevel();
  uint16_t lux = bh.readRawLevel();

  // Serial.println("---------------------------------------------");
  // Serial.print("Cahaya : ");
  // Serial.println((light_level < 20) ? "Gelap" : "Terang");
  // Serial.println((String)"Lux: "+light_level+" lx");
  // bhValue();
  log_cahaya = (light_level < 30) ? 1 : 0;
  
  Blynk.virtualWrite(V1, light_level);
  Blynk.virtualWrite(V6, log_cahaya);
  Blynk.virtualWrite(V52, log_cahaya);
  
}

void bhValue(){
  Wire.beginTransmission(0x23);
  Wire.write(0x10);
  Wire.endTransmission();

  Wire.requestFrom(0x23, 2);
  byte highByte = Wire.read();
  byte lowByte = Wire.read();
  int comByteBH = (highByte << 8) | lowByte;

  // Serial.print("High byte : 0x");
  // if(highByte < 0x10)Serial.print("0");
  // Serial.print(highByte, HEX);
  // Serial.print("\tLow byte : 0x");
  // Serial.println(lowByte, HEX);
  // Serial.print("Combined measurement : ");
  // Serial.println(comByteBH);
  // Serial.print("Perhitungan BH1750 : ");
  // Serial.println(comByteBH / 1.2);
  Blynk.virtualWrite(V45, comByteBH);
}


