#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;


class CityGraph
{
    // Graph class represents a directed graph using adjacency list representation
   
        int V; // No. of vertices
        list<int> *adj; // Pointer to an array containing adjacency lists
    public:
        CityGraph(int V); // Constructor
        void addEdge(int v, int w); // Function to add an edge to the graph
        void BFS(int s); // Prints BFS traversal from a given source s


};

