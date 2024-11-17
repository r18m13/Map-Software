/**
 * Project Untitled
 */


#ifndef _OPTIMIZATION_H
#define _OPTIMIZATION_H
#include <string>
#include <vector>

using namespace std;

class Optimization {
public: 
    double error;
    string optimizationAlgoritm;
    
/**
 * @param graph
 */
void optimize(Graph graph);
};

#endif //_OPTIMIZATION_H