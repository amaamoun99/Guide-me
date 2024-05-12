#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include "Transporatations.h" // Assuming Edge.h contains the definition of the Edge class
#include<vector>
#include<unordered_set>

using namespace std;

class Graph {

public:

    unordered_map<string, list<pair<string, Transporatations>>> adjacency_list;

public:
    Graph();
    void displayAdjacentlistforfunctions();
    void addEdge(string, string, Transporatations&);
    void updateEdge(string source, string destination);
    void removeEdge(string source, string destination);
    void displayAdjacentlist();
    void bfs(string source);
    void dfs(string source);
    bool CompleteGraph();
    void findPaths(string source, string destination, int budget);
    void findPathsHelper(string source, string destination, int budget, int currentCost, unordered_set<string>& visited, vector<string>& path, vector<string>& transportUsed, vector<pair<float, string>>& paths);
};
