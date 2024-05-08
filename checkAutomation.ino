BLYNK_WRITE(V12){
  pinvalueOtomatis = param.asInt();
}

void checkAutomation(){
  if(pinvalueOtomatis == 1){
    controlrelayAuto();
    Blynk.setProperty(V11, "isHidden", true);
    staterelayOffManual = 0;
  }else{
   Blynk.setProperty(V11, "isHidden", false);
   kanopiManual();
  }
}