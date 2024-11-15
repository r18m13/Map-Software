/**
 * Project Untitled
 */


#ifndef _SENSOR_H
#define _SENSOR_H

class Sensor {
public: 
    string type;
    string data;
    double range;
    void Port1;
    double resolution;
    
string acquireData();
    
void calibrateSensor();
};

#endif //_SENSOR_H