/**
 * Project Untitled
 */


#ifndef _ROBOT_H
#define _ROBOT_H

class Robot {
public: 
    vector<float> pose;
    void map;
    double batteryStatus;
    float velocity;
    
/**
 * @param newPose
 * @param newMap
 */
void updatePoseAndMap(vector<float> newPose, void newMap);
    
/**
 * @param destination
 */
void navigateToPoint(vector<float> destination);
};

#endif //_ROBOT_H