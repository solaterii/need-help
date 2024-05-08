void logic_kanopi() {
  
  bool conditions[][4] = {
    {0, 0, 0, 0},//Kebuka//TIDAK HUJAN, TERANG, DINGIN, TIDAK JEMUR
    {0, 0, 0, 1},//Kebuka//TIDAK HUJAN, TERANG, DINGIN, JEMUR
    {0, 1, 1, 0},//Kebuka//TIDAK HUJAN, GELAP, PANAS, TIDAK JEMUR
    {0, 0, 1, 1},//Kebuka//TIDAK HUJAN, TERANG, PANAS, JEMUR
    {0, 1, 0, 0},//Kebuka//TIDAK HUJAN, GELAP, DINGIN, TIDAK JEMUR 
    {0, 1, 0, 1},//Kebuka//TIDAK HUJAN, GELAP, DINGIN, JEMUR
    {0, 0, 1, 0},//Kebuka//TIDAK HUJAN, TERANG, PANAS, TIDAK JEMUR
    {0, 1, 1, 1},//Tertutup//TIDAK HUJAN, GELAP, PANAS, JEMUR
    {1, 0, 0, 0},//Tertutup//HUJAN, TERANG, DINGIN, TIDAK JEMUR
    {1, 0, 0, 1},//Tertutup//HUJAN, TERANG, DINGIN, JEMUR
    {1, 0, 1, 0},//Tertutup//HUJAN, TERANG, PANAS, TIDAK JEMUR
    {1, 0, 1, 1},//Tertutup//HUJAN, TERANG, PANAS, JEMUR
    {1, 1, 0, 0},//Tertutup//HUJAN, GELAP, DINGIN, TIDAK JEMUR
    {1, 1, 0, 1},//Tertutup//HUJAN, GELAP, DINGIN, JEMUR
    {1, 1, 1, 0},//Tertutup//HUJAN, GELAP, PANAS, JEMUR
    {1, 1, 1, 1},//Tertutup//HUJAN, GELAP, PANAS, JEMUR
  };

  
  for (int i = 0; i < sizeof(conditions) / sizeof(conditions[0]); ++i) {
    if (log_rain == conditions[i][0] && log_cahaya == conditions[i][1] &&
        log_suhu == conditions[i][2] && log_jemuran == conditions[i][3]) {
      log_motor = (i < 6) ? 0 : 1; 
      return;
    }
  }
}
