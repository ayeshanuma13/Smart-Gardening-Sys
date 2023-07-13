#include "arduino_secrets.h"
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include "thingProperties.h"
#define soilWet 500 
#define soilDry 750
const char* ssid = "Ayesha"; 
const char* password = "ayesha123456"; 
#define sensorPower D0
#define water_pump_pin D1

int sensorPin = A0;

void setup() {
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  Serial.begin(9600);
  delay(10);
  pinMode(D1, OUTPUT);
  initProperties();
  pinMode(water_pump_pin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  onMannualModeChange();
  delay(100);
}

void onMannualModeChange() {
  if (mannual_Mode) {
    onWaterPumpChange();
  }
  else {
    automate();
  }
}

void onWaterPumpChange() {
  if (water_Pump) {
    digitalWrite(water_pump_pin, HIGH);
  }
  else {
    digitalWrite(water_pump_pin, LOW);
  }
}
void automate()
{
  int moisture = readSensor();
  Serial.print("Analog Output: ");
  Serial.println(moisture);
  moisture_Value = 100 * (1024 - moisture) / 1024;

  if (moisture < soilWet) {
    //Serial.println("Status: Soil is too wet-Stop the Watering");
    digitalWrite(D1, LOW);
  } else if (moisture >= soilWet && moisture < soilDry) {
    //Serial.println("Status: Soil moisture is perfect");
    digitalWrite(D1, LOW);
  } else {
    //Serial.println("Status: Soil is too dry - time to water!");
    digitalWrite(D1, HIGH);
  }
  Serial.println();
}
int readSensor() {
  digitalWrite(sensorPower, HIGH); 
  delay(10); 
  int val = analogRead(sensorPin); 
  digitalWrite(sensorPower, LOW); 
  return val; 
}
void onMoistureValueChange()  {
}
