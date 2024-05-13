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
   /* Files f;
    string filename = "Graphdata.txt";
    adjacency_list = f.readTransportationData(filename);*/  
}


void Graph::addEdge(string source, string destination) {
    Transporatations  e;
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;
    for (const auto& dest : adjacency_list[source]) {
        if (dest.first == destination) {
            cout << "\n\n";
            cout<< string(padding, ' ') << "This edge already exists!\n";
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
        for (auto it = key->second.begin(); it != key->second.end();it++)
        {
            if (it->first == destination)
            {
                it = key->second.erase(it);
                break;// Update iterator after erasing
            }
            
             // Move to the next iterator if no deletion occurs
        }
    }

    auto key2 = adjacency_list.find(destination);
    if (key2 != adjacency_list.end())
    {
        for (auto it = key2->second.begin(); it != key2->second.end(); ++it)
        {
            if (it->first == source)
            {
                it = key2->second.erase(it);
                break;// Update iterator after erasing
            }
            
        }
    }
}

void Graph::displayAdjacentlistforfunctions()
{
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;
    for (const auto& entry : adjacency_list) {
        const string& source = entry.first;
        const list<pair<string, Transporatations>>& destinations = entry.second;

        cout << string(padding, ' ') << "Source: " << source << endl;
        for (const auto& destination : destinations) {
            const string& dest = destination.first;

            cout << string(padding, ' ') << "\tDestination: " << dest << endl;
        }
    }
}
void Graph::displayAdjacentlist()
{
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << string(padding, ' ') << "\t\tDisplay Adjaceny List\n"
        << string(padding, ' ') << "-------------------------------------\n";
    for (const auto& entry : adjacency_list) {
        const string& source = entry.first;
        const list<pair<string, Transporatations>>& destinations = entry.second;

        cout << string(padding, ' ') << "Source: " << source << endl;
        for (const auto& destination : destinations) {
            const string& dest = destination.first;
            const Transporatations& edge = destination.second;

            cout << string(padding, ' ') << "\tDestination: " << dest << endl;
            for (const auto& transportation : edge.transportations) {
                cout << string(padding, ' ') << "\t\tVehicle: " << transportation.Vechilename << ", Price: " << transportation.VechilePrice << endl;
            }
        }
    }
}
void Graph::bfs(string source) {
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;
    queue<string> bfs_queue;
    unordered_set<string> visited;

    visited.insert(source);
    bfs_queue.push(source);

    cout<< string(padding,' ') << "BFS starting from vertex " << source << " : ";

    while (!bfs_queue.empty()) {

        string current_vertex = bfs_queue.front();
        cout << current_vertex << " ";
        bfs_queue.pop();

        for (const auto& neighbor : adjacency_list[current_vertex]) {
            string destination = neighbor.first;

            if (visited.find(destination) == visited.end()) {
                visited.insert(destination);
                bfs_queue.push(destination);
            }
        }
    }
    cout << endl;
    system("pause");
}
void Graph::dfs(string source)
{
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;
    stack<string> dfs_stack;
    unordered_set<string> visited;
  
    visited.insert(source);
    dfs_stack.push(source);

    cout << string(padding, ' ') << "DFS starting from vertex " << source << " : ";

    while (!dfs_stack.empty()) {

        string current_vertex = dfs_stack.top();
        cout << current_vertex << " ";
        dfs_stack.pop();


        for (const auto& neighbor : adjacency_list[current_vertex]) {
            string destination = neighbor.first;


            if (visited.find(destination) == visited.end()) {
                visited.insert(destination);
                dfs_stack.push(destination);
            }
        }
    }
    cout << endl;
    system("pause");
}

bool Graph::CompleteGraph()
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
void Graph::findPaths(string source, string destination, int budget) {
    unordered_set<string> visited;
    vector<string> path;
    vector<string> transportUsed;
    vector<pair<float, string>> paths;
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;
    findPathsHelper(source, destination, budget, 0, visited, path, transportUsed, paths);
    sort(paths.begin(), paths.end());
    cout << string(padding, ' ') << "Your Options:\n";
    int i = 0;
    for (const auto& p : paths) {

        cout<< string(padding,' ') << i+1 << "-" << p.second << " | Total Payment:" << p.first << endl;
        i++;
    }
    system("pause");

}
void Graph::findPathsHelper(string source, string destination, int budget, int currentCost, unordered_set<string>& visited, vector<string>& path, vector<string>& transportUsed, vector<pair<float, string>>& paths) {
    path.push_back(source);
    if (source == destination) {
        string pathStr = "";
        for (int i = 0; i < path.size(); i++) {
            pathStr += path[i];
            if (i < transportUsed.size()) {
                pathStr += " (" + transportUsed[i] + ") ";
            }
        }
        paths.push_back({ currentCost, pathStr });
    }
    else {
        visited.insert(source);
        for (const auto& neighbor : adjacency_list[source]) {
            const string& next_vertex = neighbor.first;
            const Transporatations& transport = neighbor.second;
            for (const auto& trans : transport.transportations) {
                if (currentCost + trans.VechilePrice <= budget && visited.find(next_vertex) == visited.end()) {
                    transportUsed.push_back(trans.Vechilename);
                    findPathsHelper(next_vertex, destination, budget, currentCost + trans.VechilePrice, visited, path, transportUsed, paths);
                    transportUsed.pop_back();
                }
            }
        }
        visited.erase(source);
    }
    path.pop_back();
}





