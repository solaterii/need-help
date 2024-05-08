void rain_get(){ 
  digitalWrite(rainPowerPin, HIGH);
  delay(10);
  rainAnalog = analogRead(rainAnalogPin);
  int outputValue = map(rainAnalog, 0, 4095, 255, 0);
  digitalWrite(rainPowerPin, LOW);
  float rainVoltage = outputValue * (3.3 / 4095.0);

  // Serial.println("---------------------------------------------");
  // Serial.println((String)"Rain Analog: "+outputValue);
  // Serial.print("Rain Sensor Voltage : ");
  // Serial.print(rainVoltage,3);
  // Serial.println("V");
  
  log_rain = (outputValue >= 100) ? 1 : 0;
  Blynk.virtualWrite(V5, log_rain);
  Blynk.virtualWrite(V41, outputValue);
  Blynk.virtualWrite(V42, rainVoltage);
  Blynk.virtualWrite(V51, log_rain);
}