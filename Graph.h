#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include "Transporatations.h" // Assuming Edge.h contains the definition of the Edge class
#include<vector>

using namespace std;

class Graph {

public:

    unordered_map<string, list<pair<string, Transporatations>>> adjacency_list;

public:
    Graph();
    void addEdge(string, string, Transporatations);
    void updateEdge(string source, string destination);
    void removeEdge(string source, string destination, Transporatations e);
};
