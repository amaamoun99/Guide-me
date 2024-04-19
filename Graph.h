#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include "Edge.h" // Assuming Edge.h contains the definition of the Edge class

using namespace std;

class Graph {
	
public:
   
    unordered_map<string, list<pair<string,vector<transportation>>>> adjacency_list;
  
public:
    Graph();
    void addEdges(string u, string v, vector<transportation>& transportation);
};
