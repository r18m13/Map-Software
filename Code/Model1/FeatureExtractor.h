/**
 * Project Untitled
 */


#ifndef _FEATUREEXTRACTOR_H
#define _FEATUREEXTRACTOR_H
#include <string>
#include <vector>

using namespace std;


class FeatureExtractor {
public: 
    vector<string> extractedFeatures;
    string featureType;
    
/**
 * @param sensorData
 */
vector<string> extractFeatures(string sensorData);
    
void visualizeFeatures();
};

#endif //_FEATUREEXTRACTOR_H