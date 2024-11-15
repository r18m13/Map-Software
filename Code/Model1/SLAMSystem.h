/**
 * Project Untitled
 */


#ifndef _SLAMSYSTEM_H
#define _SLAMSYSTEM_H

class SLAMSystem {
public: 
    Graph graph;
    vector<Sensor> sensors;
    Robot robot;
    void Port1;
    double processingTime;
    string status;
    
/**
 * @param locationRequest
 */
void handleRequest(string locationRequest);
    
void performSLAM();
    
void generateMap();
    
void initializeSystem();
    
void shutdownSystem();
};

#endif //_SLAMSYSTEM_H