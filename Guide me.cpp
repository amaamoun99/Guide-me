#include "Files.h"
#include <iostream>
#include <unordered_map>
#include <list>
#include <utility> // for std::pair
#include "Transporatations.h" // Assuming Edge.h is properly defined
#include <vector>
#include"Graph.h"

using namespace std;

void main() {
    Files f;
    Graph g;
    Transporatations e;
    g.addEdge("Sharm", "Paris", e);
    g.displayAdjacentlist();
    string filename = "Graphdata.txt";
    f.WriteTransportationData(g.adjacency_list,filename);
    
    
}
