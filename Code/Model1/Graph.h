/**
 * Project Untitled
 */


#ifndef _GRAPH_H
#define _GRAPH_H
#include <string>
#include <vector>

using namespace std;


class Graph {
public: 
    vector<string> Nodes;
    double Edges;
    bool optimizationStatus;
    
/**
 * @param node
 */
void addNode(string node);
    
/**
 * @param node1
 * @param node2
 */
void addEdge(int node1, int node2);
    
void optimizeGraph();
};

#endif //_GRAPH_H