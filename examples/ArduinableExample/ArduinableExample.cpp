#include <Arduino.h>
#include <Arduinable.h>
#include <Interval.h>

class ShowTime : public Arduinable {
private:
    Interval interval = Interval(1000);

public:
    void loop() override {
        if (interval.isReady()) {
            Serial.println(millis());
        }
    }
};

Arduinable *showTime;

void setup() {
    Serial.begin(115200);
    Serial.println("Ready");
    showTime = new ShowTime();
}

void loop() {
    showTime->loop();
}
