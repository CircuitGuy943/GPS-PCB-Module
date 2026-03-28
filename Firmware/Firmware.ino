#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4;
static const int TXPin = 3;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(115200);
  Serial.println(F("L80‑RE‑M37 GPS Parser"));
  Serial.println(F("Initializing GPS module..."));
  ss.begin(GPSBaud);
  Serial.println(F("GPS serial started – waiting for fix..."));
}

void loop() {
  while (ss.available() > 0) {
    char c = ss.read();
    gps.encode(c);
  }

  if (gps.location.isValid()) {
    Serial.print(F("Latitude: "));
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(" Longitude: "));
    Serial.print(gps.location.lng(), 6);

    if (gps.altitude.isValid()) {
      Serial.print(F(" Altitude: "));
      Serial.print(gps.altitude.meters());
      Serial.print(F(" m"));
    }

    if (gps.date.isValid()) {
      Serial.print(F(" Date: "));
      Serial.print(gps.date.month());
      Serial.print(F("/"));
      Serial.print(gps.date.day());
      Serial.print(F("/"));
      Serial.print(gps.date.year());
    }
    if (gps.time.isValid()) {
      Serial.print(F(" Time: "));
      if (gps.time.hour() < 10) Serial.print(F("0"));
      Serial.print(gps.time.hour());
      Serial.print(F(":"));
      if (gps.time.minute() < 10) Serial.print(F("0"));
      Serial.print(gps.time.minute());
      Serial.print(F(":"));
      if (gps.time.second() < 10) Serial.print(F("0"));
      Serial.print(gps.time.second());
    }

    if (gps.satellites.isValid()) {
      Serial.print(F(" Satellites: "));
      Serial.print(gps.satellites.value());
    }

    if (gps.hdop.isValid()) {
      Serial.print(F(" HDOP: "));
      Serial.print(gps.hdop.hdop());
    }

    Serial.println();
    delay(1000);
  } else {
    static unsigned long lastPrint = 0;
    if (millis() - lastPrint > 1000) {
      Serial.print(F("."));
      lastPrint = millis();
    }
  }
}