/**
 * Project Untitled
 */


#ifndef _SLAMSYSTEM_H
#define _SLAMSYSTEM_H
#include <string>
#include <vector>
#include <Graph.h>
#include <Sensor.h>
#include <Robot.h>

using namespace std;

class SLAMSystem {
public: 
    Graph graph;
    vector<Sensor> sensors;
    Robot robot;
    string status;
    
/**
 * @param locationRequest
 */
void handleRequest(string locationRequest);
    
void performSLAM();
    
void generateMap();
};

#endif //_SLAMSYSTEM_H