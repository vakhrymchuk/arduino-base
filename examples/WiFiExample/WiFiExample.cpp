#include <Arduino.h>
#include <DeviceWiFi.h>
#include <Interval.h>

class WiFiExample : public DeviceWiFi {
private:
    Interval interval = Interval(2, SECOND);

public:

    WiFiExample(const char *ssid, const char *pass) : DeviceWiFi(ssid, pass) {};

    void loop() override {
        DeviceWiFi::loop();
        if (interval.isReady()) {
            Serial.println("WiFi connected. IP address: " + WiFi.localIP().toString());
        }
    }
};

Arduinable *wiFiExample;

void setup() {
    Serial.begin(115200);
    Serial.println("Ready");
    wiFiExample = new WiFiExample("ssid", "password");
}

void loop() {
    wiFiExample->loop();
}
