#include "Files.h"
#include <iostream>
#include <unordered_map>
#include <list>
#include <utility> // for std::pair
#include "Edge.h" // Assuming Edge.h is properly defined
#include <vector>
#include"Graph.h"

using namespace std;

int main() {
    // Assuming you have a filename "transportation.txt"
    string filename = "Graphdata.txt";
    Files f;
    // Call the readTransportationData function to read the transportation data
    unordered_map<string, list<pair<string, Edge>>> transportationData = f.readTransportationData(filename);

    // Output the read data for verification
    for (const auto& entry : transportationData) {
        const string& source = entry.first;
        const list<pair<string, Edge>>& destinations = entry.second;

        cout << "Source: " << source << endl;
        for (const auto& destination : destinations) {
            const string& dest = destination.first;
            const Edge& edge = destination.second;

            cout << "\tDestination: " << dest << endl;
            for (const auto& transportation : edge.transportations) {
                cout << "\t\tVehicle: " << transportation.Vechilename << ", Price: " << transportation.VechilePrice << endl;
            }
        }
    }
    Edge e1, e2;
    e1.addTransportation();
    e2.addTransportation();
    Graph g;

    g.addEdges("alex", "france", e1);
    g.addEdges("sharm", "usa", e2);
    f.WriteTransportationData(g.adjacency_list, filename);
    return 0;
}
