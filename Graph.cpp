#include "Graph.h"
#include "Files.h"
#include "Transporatations.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph() {
    Files f;
    string filename = "Graphdata.txt";
    adjacency_list = f.readTransportationData(filename);
}

void Graph::addEdge(string source, string destination, Transporatations& e) {
   
    adjacency_list[source].push_back({ destination, std::cref(e) });
    adjacency_list[destination].push_back({ source, std::cref(e) }); // For undirected graph
}

void Graph::updateEdge(string source, string destination) {
    auto key = adjacency_list.find(source);
    auto key2 = adjacency_list.find(destination);
    if (key != adjacency_list.end()) 
    {
        if (key2 != adjacency_list.end())
        {
            for (auto it1 = key->second.begin(); it1 != key->second.end(); ++it1)
            {
                for (auto it2 = key2->second.begin(); it2 != key2->second.end(); ++it2)
                {
                    if (it1->first == destination && it2->first == source)
                    {
                        it1->second.Menu();
                        it2->second = it1->second;
                        break;

                    }
                }
                
            }
        }
    }
}

void Graph::removeEdge(string source, string destination) 
{
    auto key = adjacency_list.find(source);
    if (key != adjacency_list.end()) 
    {
        for (auto it = key->second.begin(); it != key->second.end();) 
        {
            if (it->first == destination) 
            {
                it = key->second.erase(it); // Update iterator after erasing
            }
            else 
            {
                ++it; // Move to the next iterator if no deletion occurs
            }
        }
    }

    auto key2 = adjacency_list.find(destination);
    if (key2 != adjacency_list.end()) 
    {
        for (auto it = key2->second.begin(); it != key2->second.end();) 
        {
            if (it->first == source) 
            {
                it = key2->second.erase(it);
                break;// Update iterator after erasing
            }
            else 
            {
                ++it; // Move to the next iterator if no deletion occurs
            }
        }
    }
}

void Graph::displayAdjacentlist()
{
    for (const auto& entry : adjacency_list) {
        const string& source = entry.first;
        const list<pair<string, Transporatations>>& destinations = entry.second;

        cout << "Source: " << source << endl;
        for (const auto& destination : destinations) {
            const string& dest = destination.first;
            const Transporatations& edge = destination.second;

            cout << "\tDestination: " << dest << endl;
            for (const auto& transportation : edge.transportations) {
                cout << "\t\tVehicle: " << transportation.Vechilename << ", Price: " << transportation.VechilePrice << endl;
            }
        }
    }
}

