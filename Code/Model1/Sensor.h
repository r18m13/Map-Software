/**
 * Project Untitled
 */


#ifndef _SENSOR_H
#define _SENSOR_H
#include <string>
#include <vector>

using namespace std;
class Sensor {
public: 
    string type;
    string data;
    double range;
    double resolution;
    
string acquireData();
};

#endif //_SENSOR_H