void limit_jemuran() {
  int data_jemuran = digitalRead(jemuran_pin);
  // Serial.println("---------------------------------------------");
  // Serial.print("Jemuran : ");
  // Serial.println((data_jemuran == LOW) ? "Tertutup" : "Terbuka");
  log_jemuran = (data_jemuran == LOW) ? 0 : 1;
  
  Blynk.virtualWrite(V3, log_jemuran);
  Blynk.virtualWrite(V54, log_jemuran);
}