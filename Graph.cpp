#include "Graph.h"
#include "Files.h"
#include "Transporatations.h"
#include <string>
#include <vector>
#include <iostream>
#include<stack>
#include<queue>
#include<unordered_set>

using namespace std;

Graph::Graph() {
    Files f;
    string filename = "Graphdata.txt";
    adjacency_list = f.readTransportationData(filename);
}

void Graph::addEdge(string source, string destination, Transporatations& e) {
    for (const auto& dest : adjacency_list[source]) {
        if (dest.first == destination) {
            cout << "This edge already exists!\n";
            return;
        }
    }
    adjacency_list[source].push_back({ destination, e });
    adjacency_list[destination].push_back({ source, e });
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
void Graph::bfs(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, string& source) {
    // Create a queue for BFS
    queue<string> bfs_queue;

    // Create a set to keep track of visited vertices
    unordered_set<string> visited;

    // Mark the source vertex as visited and enqueue it
    visited.insert(source);
    bfs_queue.push(source);

    cout << "BFS starting from vertex " << source << " : ";

    // Iterate until the queue is empty
    while (!bfs_queue.empty()) {
        // Dequeue a vertex from the queue and print it
        string current_vertex = bfs_queue.front();
        cout << current_vertex << " ";
        bfs_queue.pop();

        // Traverse all adjacent vertices of the current vertex
        for (const auto& neighbor : adjacency_list[current_vertex]) {
            string destination = neighbor.first;

            // If the adjacent vertex has not been visited yet, mark it as visited and enqueue it
            if (visited.find(destination) == visited.end()) {
                visited.insert(destination);
                bfs_queue.push(destination);
            }
        }
    }

    cout << endl;
}
void Graph::dfs(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, string& source)
{
    stack<string> dfs_stack;
    unordered_set<string> visited;
    // Mark the source vertex as visited and enqueue it
    visited.insert(source);
    dfs_stack.push(source);

    cout << "DFS starting from vertex " << source << " : ";

    // Iterate until the queue is empty
    while (!dfs_stack.empty()) {
        // Dequeue a vertex from the queue and print it
        string current_vertex = dfs_stack.top();
        cout << current_vertex << " ";
        dfs_stack.pop();

        // Traverse all adjacent vertices of the current vertex
        for (const auto& neighbor : adjacency_list[current_vertex]) {
            string destination = neighbor.first;

            // If the adjacent vertex has not been visited yet, mark it as visited and enqueue it
            if (visited.find(destination) == visited.end()) {
                visited.insert(destination);
                dfs_stack.push(destination);
            }
        }
    }
    cout << endl;
}

bool Graph::CompleteGraph(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list)
{
    int vertexcnt = 0;
    for (const auto& source_cnt : adjacency_list) {
        vertexcnt++;
    }
    int totalEdges = 0;
    for (const auto& route : adjacency_list) {
        totalEdges += route.second.size(); // Increment the total edges by the number of destinations for each source
    }
    totalEdges = totalEdges / 2;

    if (totalEdges == (vertexcnt * (vertexcnt - 1) / 2))
        return true;
    else
        return false;

}
