void setup() {
  for (int i = 2; i < 19; i++) {
    pinMode(i, INPUT);
  }
}

void loop() {
  for (int on = 2; on < 19; on++) {
    if (on != 13) {
      pinMode(on, OUTPUT);
      digitalWrite(on, 1);
      for (int gnd = 2; gnd < 19; gnd++) {
        if (on != gnd) {
          if (gnd != 13) {
            pinMode(gnd, OUTPUT);
            digitalWrite(gnd, 0);
            //delay(1);
            pinMode(gnd, INPUT);
            //delay(500);
          }
        }
      }
      pinMode(on, INPUT);
    }
  }
}
