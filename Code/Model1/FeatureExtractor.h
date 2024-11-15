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
    
void visualizeFeatures();
};

#endif //_FEATUREEXTRACTOR_H