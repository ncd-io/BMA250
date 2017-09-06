#include "BMA250.h"

void BMA250::init(){
    Wire.begin();
    setRange();
}

void BMA250::setAddress(int a0){
    address |= a0;
};

void BMA250::setRange(){
    int rangeval = range < 8 ? range+1 : (range > 8 ? 12 : 8);
    Wire.beginTransmission(address);
    Wire.write(0x0F);
    Wire.write(rangeval);
    Wire.endTransmission();
};

void BMA250::setRange(int rng){
    range=rng;
    setRange();
};

void BMA250::setBandwidth(){
    Wire.beginTransmission(address);
    Wire.write(0x10);
    Wire.write(bandwidth);
    Wire.endTransmission();
};

void BMA250::setBandwidth(int val){
    bandwidth=val;
};

void BMA250::checkReadings(){
    Wire.beginTransmission(address);
    Wire.write(0x02);
    Wire.endTransmission();
    
    Wire.requestFrom(address, 6);
    
    // xAccel=((Wire.read()>>6) + (Wire.read()<<2));
    // yAccel=((Wire.read()>>6) + (Wire.read()<<2));
    // zAccel=((Wire.read()>>6) + (Wire.read()<<2));
    
    xAccel = Wire.read();
    xAccel |= Wire.read() << 8;
    xAccel >>= 6;
    
    yAccel = Wire.read();
    yAccel |= Wire.read() << 8;
    yAccel >>= 6;
    
    zAccel = Wire.read();
    zAccel |= Wire.read() << 8;
    zAccel >>= 6;
    
    if(xAccel > xHigh) xHigh = xAccel;
    if(yAccel > yHigh) yHigh = yAccel;
    if(zAccel > zHigh) zHigh = zAccel;
    
};
