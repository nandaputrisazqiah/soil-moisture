#include <Wire.h>

const int digital_input =  4;

void setup() {
  pinMode(digital_input, INPUT);
  Serial.begin(9600); //baud serial monitor

}

void loop() {
  int adc = analogRead(A0);
  float tegangan = adc * (3.3 / 1023.0);
  Serial.print("ADC:");
  Serial.print(adc);
  Serial.print(" | ");
  Serial.print("tegangan:");
  Serial.println(tegangan, 2);

  int status_sensor = digitalRead(digital_input);
  Serial.print("status:");

  if (status_sensor == HIGH) {
    digitalWrite(13, HIGH);  //Led builtin Arduino
    Serial.println("Kering");
  }
  else {
    digitalWrite(13, LOW);
    Serial.println("Basah");
  }
  delay(2000);
}
