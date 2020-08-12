// Set variables & configure pins
const int buttonPin = 2;
const int speakerPin = 3;
int buttonState = HIGH;  // HIGH: button released, LOW: button pressed (wg. PULLUP, siehe setup)
int checkTime = 1000;  // time span between two checks for the button being pressed
long snoozeTime = 300000;  // time span to wait before starting the alarm ((300*1000ms = 300s = 5min)
long time_now = 0;
int numberOfTones = 20;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // PULLUP: +5V bei getrenner 
  pinMode(speakerPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

// Define functions
void blinkTwice() {
    for (int i=0; i<2; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    }
}
void soundAlarm(int n) {
  for (int i=0; i<n; i++) {
    tone(speakerPin, 440);
    delay(500);
    noTone(speakerPin);
    delay(500);
  }
}

// Go
void loop() {
  delay(checkTime);
  buttonState = digitalRead(buttonPin);  // button pressed?
  if (buttonState == LOW) {
    blinkTwice();
    time_now = millis();
    while (millis() < time_now+snoozeTime) {
      //wait
    }
    soundAlarm(numberOfTones);
  }
}
