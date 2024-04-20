#include "Graph.h"
#include "Edge.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph() {

}

void Graph::addEdges(string source, string destination, Edge e) {

    adjacency_list[source].push_back({ destination, e });
    adjacency_list[destination].push_back({ source, e }); // For undirected graph
}

