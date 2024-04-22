#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include "Edge.h" // Assuming Edge.h contains the definition of the Edge class
#include<vector>

using namespace std;

class Graph {

public:

    unordered_map<string, list<pair<string,Edge>>> adjacency_list;

public:
    Graph();
    void addEdges(string, string, Edge);
};
