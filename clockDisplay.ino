void clockDisplay()
{
  // You can call hour(), minute(), ... at any time
  // Please see Time library examples for details
  
  String currentTime = String(hour()) + ":" + minute() + ":" + second();
  String currentDate = String(day()) + " " + month() + " " + year();
  Serial.print("Current time: ");
  Serial.print(currentTime);
  Serial.print(" ");
  Serial.print(currentDate);
  Serial.println();
  // Blynk.virtualWrite(V7, currentTime);
  // Blynk.virtualWrite(V8, currentDate);
  
}
