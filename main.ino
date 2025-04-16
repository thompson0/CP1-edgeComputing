int ledYellowPin = 7;
int ledRedPin = 9;
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
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPhotoSensor);
  Serial.println(ldrValue);
  unsigned long currentTime = millis();

  
  digitalWrite(ledGreenPin, LOW);
  digitalWrite(ledYellowPin, LOW);
  digitalWrite(ledRedPin, LOW);

  
  if (ldrValue >= 300 && ldrValue <= 400) {
    digitalWrite(ledGreenPin, HIGH);
    noTone(boozerPin);
    boozerActive = false;
  } 
  else if (ldrValue >= 500 && ldrValue <= 600) {
    digitalWrite(ledYellowPin, HIGH);
    noTone(boozerPin);
    boozerActive = false;
  } 
  else if (ldrValue > 600) {
    digitalWrite(ledRedPin, HIGH);
    if (!boozerActive) {
      tone(boozerPin, 262, 3000);  
      boozerStartTime = currentTime;
      boozerActive = true;
    }
  } 
  else {
   
    noTone(boozerPin);
    boozerActive = false;
  }

  delay(200);
}