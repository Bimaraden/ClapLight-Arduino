#define sensor 2
#define lamp 13
int count = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(lamp, OUTPUT);
}

void loop() {
  if (digitalRead(sensor) == HIGH) {
    delay(100);  // Debounce delay
    if (digitalRead(sensor) == HIGH) {  // Check if the signal is still high
      count++;
      if (count == 1) {
        digitalWrite(lamp, HIGH);  // Turn on the lamp
      } else if (count == 2) {
        digitalWrite(lamp, LOW);  // Turn off the lamp
        count = 0;
      }
      while (digitalRead(sensor) == HIGH);  // Wait until the sound signal goes low
    }
  }
  delay(10);  // Short delay to avoid rapid switching
}
