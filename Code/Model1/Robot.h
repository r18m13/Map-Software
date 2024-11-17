/**
 * Project Untitled
 */


#ifndef _ROBOT_H
#define _ROBOT_H
#include <string>
#include <vector>

using namespace std;
class Robot {
public: 
    vector<float> pose;
    double map;
    float velocity;
    
/**
 * @param newPose
 * @param newMap
 */
void updatePoseAndMap(vector<float> newPose, double newMap);
    
/**
 * @param destination
 */
void navigateToPoint(vector<float> destination);
};

#endif //_ROBOT_H