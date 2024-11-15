/**
 * Project Untitled
 */


#ifndef _FEATUREEXTRACTOR_H
#define _FEATUREEXTRACTOR_H

class FeatureExtractor {
public: 
    vector<string> extractedFeatures;
    string featureType;
    
/**
 * @param sensorData
 */
vector<string> extractFeatures(string sensorData);
    
/**
 * @param rawFeatures
 */
vector<string> filterFeatures(vector<string> rawFeatures);
    
void visualizeFeatures();
};

#endif //_FEATUREEXTRACTOR_H