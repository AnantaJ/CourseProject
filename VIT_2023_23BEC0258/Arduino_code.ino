int irPin = 2;        // IR output connected here
int buzzerPin = 9;
unsigned long lastOpen = 0;
unsigned long threshold = 4000;

void setup() {
  pinMode(irPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int eyeStatus = digitalRead(irPin); // HIGH = eye open, LOW = eye closed (adjust as needed)
    
  if ((eyeStatus == HIGH)) {
    lastOpen = millis();
    digitalWrite(buzzerPin, LOW);
  } else {
    if ((millis() - lastOpen > threshold)) {
      digitalWrite(buzzerPin, HIGH); // Drowsy detected
      Serial.println("Alert!!!!!!!!!!!!!!!!!");
    }
  }

  delay(100);
}