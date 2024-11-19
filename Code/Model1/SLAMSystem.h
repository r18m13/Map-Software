/**
 * Project Untitled
 */


#ifndef _SLAMSYSTEM_H
#define _SLAMSYSTEM_H

class SLAMSystem {
public: 
    void graph;
    void sensors;
    void robot;
    
void handleRequest();
    
void performSLAM();
    
void generateMap();
};

#endif //_SLAMSYSTEM_H