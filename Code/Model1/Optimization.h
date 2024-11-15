/**
 * Project Untitled
 */


#ifndef _OPTIMIZATION_H
#define _OPTIMIZATION_H

class Optimization {
public: 
    double error;
    String optimizationAlgoritm;
    double convergenceRate;
    
/**
 * @param graph
 */
void optimize(Graph graph);
    
double evaluatePerformance();
};

#endif //_OPTIMIZATION_H