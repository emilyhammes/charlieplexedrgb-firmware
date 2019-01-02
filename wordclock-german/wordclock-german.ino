const unsigned int BUTTON = 19; // pin of button
unsigned long _delay = 0; // Button continuous press delay
unsigned long _t = 900000; // Next time jump
unsigned int _m = 0; // minute displayed
unsigned int _h = 11; // hour displayed

/**
 * Definition of LEDs that need be be light up in order to show
 * a specific word on the word clock.
 */
// Line 1: KURZDREIVIERTELÄ (1-16)
const unsigned int kurz[] = {1, 2, 3, 4, 0};
const unsigned int dreiviertel[] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
const unsigned int viertel[] = {9, 10, 11, 12, 13, 14, 15, 0};
// Line 2: VORNACHPUNKTHALB (17-32)
const unsigned int vor[] = {17, 18, 19, 0};
const unsigned int nach[] = {20, 21, 22, 23, 0};
const unsigned int punkt[] = {24, 25, 26, 27, 28, 0};
const unsigned int halb[] = {29, 30, 31, 32, 0};
// Line 3: ZWÖLFÜNFZWEINSAU (33-48)
const unsigned int zwolf[] = {33, 34, 35, 36, 37, 0};
const unsigned int funf[] = {37, 38, 39, 40, 0};
const unsigned int zwei[] = {41, 42, 43, 44, 0};
const unsigned int eins[] = {43, 44, 45, 46, 0};
// Line 4: SECHSIEBENEUNELF (49-64)
const unsigned int sechs[] = {49, 50, 51, 52, 53, 0};
const unsigned int sieben[] = {53, 54, 55, 56, 57, 58, 0};
const unsigned int neun[] = {58, 59, 60, 61, 0};
const unsigned int elf[] = {62, 63, 64, 0};
// Line 5: DREIVIERACHTZEHN (65-80)
const unsigned int drei[] = {65, 66, 67, 68, 0};
const unsigned int vier[] = {69, 70, 71, 72, 0};
const unsigned int acht[] = {73, 74, 75, 76, 0};
const unsigned int zehn[] = {77, 78, 79, 80, 0};

/**
 * Definition of the pins that are connected to an LED.
 * For LED n the pin:
 *   (n*4)-4 => ground
 *   (n*4)-3 => red
 *   (n*4)-2 => green
 *   (n*4)-1 => blue
 */
const unsigned int LEDMAP[] = {
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

/** 
 * This array represents the current status of the LED screen
 * 0 means the LED is nurned of, 1-7 corresponds to a color.
 */
unsigned int _screen[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0,
  2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/**
 * In german there are two ways to express the current time.
 * In the moment you plug in the power, the state of the button controlls which way is used.
 * 
 *   (IDIOM == false, btn pressed) => "viertel eins", "halb eins", "dreiviertel eins", "punkt eins"
 *   (IDIOM == true, btn released) => "viertel nach zwölf", "halb eins", "viertel vor eins", "punkt eins"
 */
const boolean IDIOM = digitalRead(BUTTON);

// Colors in which a LED can light up.
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

/**
 * \brief Initially set all used pins of the Arduino to the desired state
 */
void setup() {
  for (int i = 2; i < 19; i++) {
    pinMode(i, INPUT);
  }
  pinMode(BUTTON, INPUT_PULLUP);
}

/**
 * \brief Turnes on and off a LED in the defined color.
 * 
 *   This function is called by the runloop once each loop for every LED that should light up.
 *   Through the speed of the loop and switching it fr the human eye it seems as if all LEDs glow.
 *   
 *   LEDMAP is used to determine which pin of the Arduino a LED is connected to.
 * 
 * \param aLed LED that should light up.
 * \param aColor Color in which the LED should light up.
 */
void lightUp(const unsigned int aLed, const enum color aColor) {
  const unsigned int lGnd = LEDMAP[aLed * 4 - 4];
  const unsigned int lRed = LEDMAP[aLed * 4 - 3];
  const unsigned int lGreen = LEDMAP[aLed * 4 - 2];
  const unsigned int lBlue = LEDMAP[aLed * 4 - 1];
  
  pinMode(lGnd, OUTPUT);
  digitalWrite(lGnd, 0);

  pinMode(lRed, OUTPUT);
  digitalWrite(lRed, aColor & RED);
  pinMode(lRed, INPUT);

  pinMode(lGreen, OUTPUT);
  digitalWrite(lGreen, aColor & GREEN);
  pinMode(lGreen, INPUT);

  pinMode(lBlue, OUTPUT);
  digitalWrite(lBlue, aColor & BLUE);
  pinMode(lBlue, INPUT);

  pinMode(lGnd, INPUT);
}

/**
 * \brief This function modifies the state of the screen and turnd the specified LEDs to the specified color.
 * 
 *   In case the time that should be displayed has changed this function is used by nextTime() to activate the
 *   new words on the screen.
 * 
 * \param aLeds LEDs to turn to color aColor on the screen.
 * \param aColor Color to which the LED should be set.
 */
void draw(const unsigned int aLeds[], const color aColor) {
  for (int i = 0; aLeds[i] != 0; i++) {
    _screen[aLeds[i] - 1] = aColor;
  }
}

/**
 * \brief Switches the clock to the next quarter of the hour
 * 
 *   Moves the clock 15min foreward in time and draws the new time on the screen.
 *   Called either when counter _t is passed or button is pressed for adjustment.
 */
void nextTime() {
  // Push time forward by 15min
  _m = (_m + 15) % 60;
  if (_m == 15 && IDIOM == false)
    _h = (_h + 1) % 12;
  if (_m == 30 && IDIOM == true)
    _h = (_h + 1) % 12;

  // Erase screen
  memset(_screen, 0, sizeof _screen);

  // Randomly choose color of the words
  const unsigned int lC = random(1, 7);

  // Draw new words
  if ( IDIOM == false ) {
    switch (_m) {
      case 0: draw(punkt, lC); break;
      case 15: draw(viertel, lC); break;
      case 30: draw(halb, lC); break;
      case 45: draw(dreiviertel, lC); break;      
    }
  } else {
    switch (_m) {
      case 0: draw(punkt, lC); break;
      case 15: draw(viertel, lC); draw(nach, lC); break;
      case 30: draw(halb, lC); break;
      case 45: draw(viertel, lC); draw(vor, lC); break;
    }
  }

  switch (_h + 1) {
    case 1: draw(eins, lC); break;
    case 2: draw(zwei, lC); break;
    case 3: draw(drei, lC); break;
    case 4: draw(vier, lC); break;
    case 5: draw(funf, lC); break;
    case 6: draw(sechs, lC); break;
    case 7: draw(sieben, lC); break;
    case 8: draw(acht, lC); break;
    case 9: draw(neun, lC); break;
    case 10: draw(zehn, lC); break;
    case 11: draw(elf, lC); break;
    case 12: draw(zwolf, lC); break;
  }
}

/**
 * \brief Runloop of the clock
 * 
 *   After the setup() function completed, this function is called over and over again.
 *   It allows reacting on the current state of the clock and allows us to light up the LEDs.
 */
void loop() {
  // Adjust clock time if button is pressed
  if (digitalRead(BUTTON) == false && _delay < millis()) {
    nextTime();
    _t = millis() + 900000;
    _delay = millis() + 500;
  }

  // Move to the next quarter of the hour if the conter _t has been passed
  if (millis() > _t) {
    nextTime();
    _t = _t + 900000;
  }

  // Lightup all LEDs of the screen
  for (int led = 1; led < 81 ; led++) {
    if (_screen[led - 1] > 0 ) {
      lightUp(led, _screen[led - 1]);
    }
  }
}

