#!/usr/bin/python
# -*- coding: utf-8 -*-
import networkx as nx

# Create a graph
#G = nx.Graph()

class Graph:
    def __init__(self):
        self.Part1 = None
        self.Nodes = None
        self.Edges = None

    def addNode(G, j, pose_temp):
        G.add_node(j, pose=pose_temp)
        pass

    def addEdge(G, i, j, pose_1):
        G.add_edge(i, j, transformation=pose_1)
        return i+1, j+1
        pass

    def optimizeGraph(self, ):
        pass
