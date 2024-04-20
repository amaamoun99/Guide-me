#include "Edge.h"
#include <iostream>
#include <vector>
#include<list>
#include"Graph.h"
#include <string>

using namespace std;



void main()
{
    Edge e1, e2;
    e1.addTransportation();
    e1.addTransportation();
    e1.addTransportation();
    e1.updateTransportation();
    e2.addTransportation();
    e2.addTransportation();
    Graph g;

    g.addEdges("Cairo", "Giza", e1);
    g.addEdges("Cairo", "Beni Suef", e2);
    for (const auto& vertex_pair : g.adjacency_list) {
        cout << "\nVertex " << vertex_pair.first << ":";
        for (const auto& adjacent_vertex_pair : vertex_pair.second) {
            cout << "\nAdjacent vertex: " << adjacent_vertex_pair.first;
            for (const auto& trasportationss : adjacent_vertex_pair.second.transportations)
            {
                cout << "\nTransportation Name:" << trasportationss.Vechilename << " \nTransportation Price:" << trasportationss.VechilePrice;
            }
        }
    }


}
