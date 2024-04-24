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

void Graph::addEdge(string source, string destination, Transporatations e) {
   
    adjacency_list[source].push_back({ destination, e });
    adjacency_list[destination].push_back({ source, e }); // For undirected graph
}

void Graph::updateEdge(string source, string destination) {
    auto key = adjacency_list.find(source);
    if (key != adjacency_list.end()) 
    {
        for (auto it = key->second.begin(); it != key->second.end(); ++it) 
        {
            if (it->first == destination) 
            {
                it->second.Menu();
                break; // No need to continue searching if destination is found
            }
        }
    }
}

void Graph::removeEdge(string source, string destination, Transporatations e) 
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

