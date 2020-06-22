#include <Blynk.h>
#include <Wire.h>
#include <ESP8266WiFi.h> //library esp8266
#include <BlynkSimpleEsp8266.h> //library BLYNK

#define BLYNK_PRINT Serial

BlynkTimer timer;

char auth[] = "IliWSUi-pTLbvvJElQZW14UaoPhMscBR"; //cek email masing2 setelah setting di aplikasi BLYNK

char ssid[] = "Hotspot pribadi"; //nama wifi
char pass[] = "workmodeon"; //password wifi

void myTimerEvent()
{
  int adc = analogRead(A0); //PIN ADC di NODEMCU
  float tegangan = adc * (3.3 / 1023.0);
  Blynk.virtualWrite(V0,  adc); //Virtual wire "0" untuk data pembacaan ADC
  Blynk.virtualWrite(V1,  tegangan); //Virtual wire "1" untuk data pembacaan ADC
}

void setup()
{
  Serial.begin(9600); //baud serial monitor
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent); //1000L = 1 detik
}

void loop()
{
  Blynk.run();
  timer.run();
}
