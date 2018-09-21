#ifndef SMARTHATA_DEVICEWIFI_H
#define SMARTHATA_DEVICEWIFI_H

#include <ESP8266WiFi.h>
#include "Arduinable.h"
#include "Stopwatch.h"

class DeviceWiFi : public Arduinable {

    const char *ssid, *pass;

    const unsigned int connectionTimeout;

public:

    DeviceWiFi(const char *ssid, const char *pass, const unsigned int connectionTimeout = 20000) :
            ssid(ssid),
            pass(pass),
            connectionTimeout(connectionTimeout) {

        if (WiFi.getMode() != WIFI_STA) {
            WiFi.mode(WIFI_STA);
        }

        loop();
    }

    void loop() override {
        if (!WiFi.isConnected()) {
            findAccessPoint();
            connectToAccessPoint();
        }
    }

private:

    bool findAccessPoint() const {
        bool accessPointFound = false;
        int numberOfNetworks = WiFi.scanNetworks();
        Serial.println("WiFi Networks: " + String(numberOfNetworks));
        for (byte i = 0; i < numberOfNetworks; i++) {
            Serial.printf("Network name: [%20s] Signal strength: %i\n", WiFi.SSID(i).c_str(), WiFi.RSSI(i));
            if (WiFi.SSID(i).equals(ssid)) {
                accessPointFound = true;
            }
        }
        if (!accessPointFound) {
            Serial.printf("\n\n\n>>>\tAccess Point [%20s] not found\n\n\n", ssid);
        }
        return accessPointFound;
    }

    void connectToAccessPoint() const {
        Serial.print("Connecting to " + String(ssid));
        WiFi.begin(ssid, pass);
        Stopwatch stopwatch;
        while (!WiFi.isConnected()) {
            blink();
            if (stopwatch.isMoreThan(connectionTimeout)) {
                Serial.println("\n\n\n>>>\tConnection to Access Point [" + String(ssid) + "] Timeout\n\n\n");
                return;
            }
        }
        Serial.println();
        float connectionTime = stopwatch.time() * 0.001f;
        Serial.println("WiFi connected " + String(connectionTime) + " sec. IP address: " + WiFi.localIP().toString());
    }

    void blink(unsigned int delayMs = 100) const {
        Serial.write('.');
        digitalWrite(LED_BUILTIN, HIGH);
        delay(delayMs);
        digitalWrite(LED_BUILTIN, LOW);
        delay(delayMs);
    }

};

#endif
