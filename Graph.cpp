#include "Graph.h"
#include "Edge.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph() {

}

void Graph::addEdges(string source, string destination, vector<transportation>& transportation) {
   
    // Add edges to adjacency_list
    adjacency_list[source].push_back({ destination, transportation });
    adjacency_list[destination].push_back({ source, transportation }); // For undirected graph
}

