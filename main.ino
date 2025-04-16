int ledRedPin = 13;
int ledYellowPin = 12;
int ledGreenPin = 11;
int ldrPhotoSensor = A0;

int boozerPin = 8;
unsigned long boozerStartTime = 0;
bool boozerActive = false;

void setup() {
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(boozerPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int ldrValue = analogRead(ldrPhotoSensor);
  Serial.println(ldrValue);
  unsigned long currentTime = millis();

  digitalWrite(ledGreenPin, LOW);
  digitalWrite(ledYellowPin, LOW);
  digitalWrite(ledRedPin, LOW);

  if (ldrValue < 600) {
    digitalWrite(ledRedPin, HIGH);
    noTone(boozerPin);
    boozerActive = false;
  } 
  else if (ldrValue < 1000) {
    digitalWrite(ledYellowPin, HIGH);
    if (!boozerActive) {
      tone(boozerPin, 262, 3000);
      boozerStartTime = currentTime;
      boozerActive = true;
    }
  } 
  else {
    digitalWrite(ledGreenPin, HIGH);
    noTone(boozerPin);
    boozerActive = false;
  }

  delay(200);
}
