int red;
int gnd;
int green;
int blue;
unsigned long t = 300000;
int m = 0;
int h = 1;

int mtwenty[] = {1, 2, 3, 4, 5, 6, 0};
int mquarter[] = {7, 8, 9, 10, 11, 12, 13, 0};
int mten[] = {14, 15, 16, 0};
int mhalf[] = {17, 18, 19, 20, 0};
int mfive[] = {20, 21, 22, 23, 0};
int past[] = {28, 29, 30, 31, 0};
int till[] = {24, 25, 26, 27, 0};
int to[] = {31, 32, 0};
int three[] = {33, 34, 35, 36, 37, 0};
int eight[] = {37, 38, 39, 40, 41, 0};
int ten[] = {41, 42, 43, 0};
int seven[] = {44, 45, 46, 47, 48, 0};
int four[] = {49, 50, 51, 52, 0};
int five[] = {54, 55, 56, 57, 0};
int twelve[] = {59, 60, 61, 62, 63, 64, 0};
int two[] = {65, 66, 67, 0};
int one[] = {67, 68, 69, 0};
int eleven[] = {69, 70, 71, 72, 73, 74, 0};
int nine[] = {74, 75, 76, 77, 0};
int six[] = {78, 79, 80, 0};

const int ledmap [] = {
  2, 3, 4, 5,
  3, 2, 4, 5,
  4, 2, 3, 5,
  5, 2, 3, 4,
  6, 2, 3, 4,
  7, 2, 3, 4,
  8, 2, 3, 4,
  9, 2, 3, 4,
  10, 2, 3, 4,
  11, 2, 3, 4,
  12, 2, 3, 4,
  14, 2, 3, 4,
  15, 2, 3, 4,
  16, 2, 3, 4,
  17, 2, 3, 4,
  18, 2, 3, 4,
  2, 6, 7, 8,
  3, 6, 7, 8,
  4, 6, 7, 8,
  5, 6, 7, 8,
  6, 5, 7, 8,
  7, 5, 6, 8,
  8, 5, 6, 7,
  9, 5, 6, 7,
  10, 5, 6, 7,
  11, 5, 6, 7,
  12, 5, 6, 7,
  14, 5, 6, 7,
  15, 5, 6, 7,
  16, 5, 6, 7,
  17, 5, 6, 7,
  18, 5, 6, 7,
  2, 9, 10, 11,
  3, 9, 10, 11,
  4, 9, 10, 11,
  5, 9, 10, 11,
  6, 9, 10, 11,
  7, 9, 10, 11,
  8, 9, 10, 11,
  9, 8, 10, 11,
  10, 8, 9, 11,
  11, 8, 9, 10,
  12, 8, 9, 10,
  14, 8, 9, 10,
  15, 8, 9, 10,
  16, 8, 9, 10,
  17, 8, 9, 10,
  18, 8, 9, 10,
  2, 12, 14, 15,
  3, 12, 14, 15,
  4, 12, 14, 15,
  5, 12, 14, 15,
  6, 12, 14, 15,
  7, 12, 14, 15,
  8, 12, 14, 15,
  9, 12, 14, 15,
  10, 12, 14, 15,
  11, 12, 14, 15,
  12, 11, 14, 15,
  14, 11, 12, 15,
  15, 11, 12, 14,
  16, 11, 12, 14,
  17, 11, 12, 14,
  18, 11, 12, 14,
  2, 16, 17, 18,
  3, 16, 17, 18,
  4, 16, 17, 18,
  5, 16, 17, 18,
  6, 16, 17, 18,
  7, 16, 17, 18,
  8, 16, 17, 18,
  9, 16, 17, 18,
  10, 16, 17, 18,
  11, 16, 17, 18,
  12, 16, 17, 18,
  14, 16, 17, 18,
  15, 16, 17, 18,
  16, 15, 17, 18,
  17, 15, 16, 18,
  18, 15, 16, 17
};

enum color {
  BLACK = 0,
  RED = 1,
  GREEN = 2,
  YELLOW = 3,
  BLUE = 4,
  PURPLE = 5,
  AQUA = 6,
  WHITE = 7
};

int screen [] = {
  1, 2, 3, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 5, 6, 7,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  3, 4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int button = 19;
unsigned long timeset = 0;

void setup() {
  t = millis();
  for (int i = 2; i < 19; i++) {
    pinMode(i, INPUT);
  }
  pinMode(button, INPUT_PULLUP);
}

int ledOn(int gnd, int red, int green, int blue, enum color c) {
  pinMode(gnd, OUTPUT);
  digitalWrite(gnd, 0);

  pinMode(red, OUTPUT);
  digitalWrite(red, c & RED);
  pinMode(red, INPUT);

  pinMode(green, OUTPUT);
  digitalWrite(green, c & GREEN);
  pinMode(green, INPUT);

  pinMode(blue, OUTPUT);
  digitalWrite(blue, c & BLUE);
  pinMode(blue, INPUT);

  pinMode(gnd, INPUT);

}

void draw (int leds[], color c) {
  for (int i = 0; leds[i] != 0; i++) {
    screen[leds[i] - 1] = c;
  }
}

void nexttime() {
  m = m + 5;
  if (m == 60) {
    m = 0;
  }
  if (m == 35) {
    h = h + 1;
  }
  if (h > 12) {
    h = 1;
  }
  memset(screen, 0, sizeof screen);

  switch (m) {
    case 5: draw(mfive, random(1, 7)); draw(past, random(1, 7)); break;
    case 10: draw(mten, random(1, 7)); draw(past, random(1, 7)); break;
    case 15: draw(mquarter, random(1, 7)); draw(past, random(1, 7)); break;
    case 20: draw(mtwenty, random(1, 7)); draw(past, random(1, 7)); break;
    case 25: draw(mtwenty, random(1, 7)); draw(mfive, random(1, 7)); draw(past, random(1, 7)); break;
    case 30: draw(mhalf, random(1, 7)); draw(past, random(1, 7)); break;
    case 35: draw(mtwenty, random(1, 7)); draw(mfive, random(1, 7)); draw(to, random(1, 7)); break;
    case 40: draw(mtwenty, random(1, 7)); draw(till, random(1, 7)); break;
    case 45: draw(mquarter, random(1, 7));  draw(till, random(1, 7)); break;
    case 50: draw(mten, random(1, 7)); draw(till, random(1, 7)); break;
    case 55: draw(mfive, random(1, 7)); draw(to, random(1, 7)); break;
  }

  switch (h) {
    case 1: draw(one , random (1, 7)); break;
    case 2: draw(two , random (1, 7)); break;
    case 3: draw(three , random (1, 7)); break;
    case 4: draw(four , random (1, 7)); break;
    case 5: draw(five , random (1, 7)); break;
    case 6: draw(six , random (1, 7)); break;
    case 7: draw(seven , random (1, 7)); break;
    case 8: draw(eight , random (1, 7)); break;
    case 9: draw(nine , random (1, 7)); break;
    case 10: draw(ten , random (1, 7)); break;
    case 11: draw(eleven , random (1, 7)); break;
    case 12: draw(twelve , random (1, 7)); break;
  }
}

void loop() {
  if (digitalRead(19) == 0 && timeset < millis()) {
    nexttime();
    timeset = millis() + 500;
  }

  if (millis() > t) {
    nexttime();
    t =  t + 300000;
  }

  for (int led = 1; led < 81 ; led++) {
    if (screen[led - 1] > 0 ) {
      gnd = ledmap[led * 4 - 4];
      red = ledmap[led * 4 - 3];
      green = ledmap[led * 4 - 2];
      blue = ledmap[led * 4 - 1];
      ledOn(gnd, red, green, blue, screen[led - 1]);
    }
  }
}
