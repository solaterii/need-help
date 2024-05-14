void cek_i2c() {
  Serial.println(F("Sensor test"));
  if (!rtc.begin()) {
   Serial.println("Could not find a valid RTCDS3231, check wiring!");
   while (1);
   }

  bool statusbh = bh.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23);
  if (!statusbh) {
    Serial.println("Could not find a valid BH1750 sensor, check wiring!");
    while (1); 
  }
  
  Wire.begin();
  sht.begin();

  Serial.println("Sensor Connected");
}
