#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2
#define ALARM_LED 7
#define DOOR_PIN 3

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();

  pinMode(ALARM_LED, OUTPUT);
  pinMode(DOOR_PIN, INPUT_PULLUP);

  Serial.print("Talalt szenzorok: ");
  Serial.println(sensors.getDeviceCount());
}

void loop() {
  sensors.requestTemperatures();

  float rackTop = sensors.getTempCByIndex(0);
  float rackBottom = rackTop - 2.0;
  float avgTemp = (rackTop + rackBottom) / 2.0;

  bool doorOpen = (digitalRead(DOOR_PIN) == LOW);
  bool alarm = (avgTemp > 30.0) || doorOpen;

  digitalWrite(ALARM_LED, alarm ? HIGH : LOW);

  Serial.print("RackTop=");
  Serial.print(rackTop);
  Serial.print(", RackBottom=");
  Serial.print(rackBottom);
  Serial.print(", Avg=");
  Serial.print(avgTemp);
  Serial.print(", Door=");
  Serial.print(doorOpen ? "OPEN" : "CLOSED");
  Serial.print(", Alarm=");
  Serial.println(alarm ? "ON" : "OFF");

  delay(1000);
}
