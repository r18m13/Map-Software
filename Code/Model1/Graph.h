/**
 * Project Untitled
 */


#ifndef _GRAPH_H
#define _GRAPH_H

class Graph {
public: 
    void Part1;
    vector<string> Nodes;
    void Edges;
    vector<vector<double>> costMatrix;
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
    
/**
 * @param nodeIndex
 */
void removeNode(int nodeIndex);
    
/**
 * @param node1
 * @param node2
 */
void removeEdge(int node1, int node2);
};

#endif //_GRAPH_H