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
    void MainMenu(Graph &g);
    void addEdge(string, string, Transporatations&);
    void updateEdge(string source, string destination);
    void removeEdge(string source, string destination);
    void displayAdjacentlist();
    void bfs(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, string source);
    void dfs(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, string source);
    bool CompleteGraph(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list);
    void findPaths(string source, string destination, int budget, unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list);
    void findPathsHelper(string source, string destination, int budget, int currentCost, unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, unordered_set<string>& visited, vector<string>& path, vector<string>& transportUsed, vector<pair<float, string>>& paths);
};
