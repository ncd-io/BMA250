#include "spark_wiring_i2c.h"
#include "spark_wiring_constants.h"

class BMA250{
public:
    int address = 0x18;
    int xAccel=0;
    int yAccel=0;
    int zAccel=0;
    
    int xHigh=0;
    int yHigh=0;
    int zHigh=0;
    
    //Range is in +-/g the available ranges are 2,4,8, and 16
    int range=2;
    //Bandwidths affect the sampling rate, and are explained on table 4 of the data sheet
    int bandwidth=8; // 1000, or 7.81 Hz
    
    void init();
    void setAddress(int a0);
    
    void setRange();
    void setRange(int rng);
    
    void setBandwidth();
    void setBandwidth(int val);
    
    void checkReadings();
    int resetHigh(String cmd);
};
