#define relay 10
int LED = 9;
int LDR = A0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(LDR, INPUT);
}

void blink(int times, int duration = 200) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED, HIGH);
    delay(duration);
    digitalWrite(LED, LOW);
    delay(duration);
  }
}

void loop() {
  int LDRValue = analogRead(LDR);
  Serial.print("Brightness (LDR) = ");
  Serial.print(LDRValue);

  if (LDRValue > 700) {
    Serial.println(" → Bright");
    digitalWrite(LED, HIGH);
    Serial.println("Lamp off.");

  } 
  else if (LDRValue > 250 && LDRValue <= 700) {
    delay(3u000);
    Serial.println(" → Slightly dark");
    blink(1); // blinks once
    digitalWrite(LED, LOW);
    digitalWrite(relay, LOW);
    
  }
  else {
    Serial.println(" → Dark");
    digitalWrite(LED, LOW);
    digitalWrite(relay, LOW);
    Serial.println("Lamp on!");
    delay(2000); // Pause between each measurement  
  }
}