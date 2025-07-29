const int ledPins[] = {2, 3, 4, 5}; // Set to your connected pin numbers
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);
const int buttonPin = 8;

int pattern = 0;
bool lastButtonState = HIGH;
bool buttonPressed = false;

void setup() {
  for (int i = 0; i < numLeds; i++) pinMode(ledPins[i], OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Internal pull-up resistor
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    pattern = (pattern + 1) % 3;    // Cycle through 3 patterns
    buttonPressed = true;
    delay(200);                     // Debounce
  }
  lastButtonState = currentButtonState;

  if (buttonPressed) {
    buttonPressed = false;
  }

  switch (pattern) {
    case 0: runningLight(); break;
    case 1: blinkAll(); break;
    case 2: alternatePairs(); break;
  }
}

void runningLight() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}
void blinkAll() {
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], HIGH);
  delay(200);
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], LOW);
  delay(200);
}
void alternatePairs() {
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], (i % 2 == 0) ? HIGH : LOW);
  delay(300);
  for (int i = 0; i < numLeds; i++) digitalWrite(ledPins[i], (i % 2 == 1) ? HIGH : LOW);
  delay(300);
}

