// This #include statement was automatically added by the Particle IDE.
#include "BMA250.h"

BMA250 accel;

void setup() {
    accel.init();
    Particle.variable("xCurrent", accel.xAccel);
    Particle.variable("yCurrent", accel.yAccel);
    Particle.variable("zCurrent", accel.zAccel);
    Particle.variable("xHigh", accel.xHigh);
    Particle.variable("yHigh", accel.yHigh);
    Particle.variable("zHigh", accel.zHigh);
    Particle.function("reset", resetHigh);
}

int resetHigh(String cmd){
    accel.xHigh=0;
    accel.yHigh=0;
    accel.zHigh=0;
    return 1;
}

int lastChecked=0;
void loop() {
    int now = millis();
    if(now-lastChecked > 100){
        lastChecked=now;
        accel.checkReadings();
    }
}
