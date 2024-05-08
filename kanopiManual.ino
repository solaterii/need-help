BLYNK_WRITE(V11){
  pinvalueManual = param.asInt();
}

void kanopiManual(){
  switch (pinvalueManual) {
    case 0: { 
      controlrelayOpen(log_kanopi);
      staterelayOffManual = 0;
      break;
    }
    case 1: {
      controlrelayOff();
      staterelayOffManual = 1;
      break;
    } 
    case 2: {
      controlrelayClose(log_kanopi);
      staterelayOffManual = 0;
      break;
    }

  }
}
