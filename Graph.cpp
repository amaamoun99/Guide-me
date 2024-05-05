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
void Graph::MainMenu(Graph &graph)
{   
    int choice;  
    string source;
    string destination;
    Transporatations transport;
    bool flag = true;
    while (flag)
    {
        cout << "1-Traverse the graph" << endl << "2-Edit Graph" << endl << "3-Check whether the graph is Complete or not" << endl;
        cout << "4-AMNY FYH maps" << endl << "5-Exit the program" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int choice2;

            cout << "1-BFS" << endl << "2-DFS" << endl << "3-Go back to Main Menu" << endl;
            cin >> choice2;
            switch (choice2) {

            case 1:
                cout << "Enter the Source" << endl;
                cin >> source;
                graph.bfs(graph.adjacency_list, source);
                break;
            case 2:
                cout << "Enter the Source" << endl;
                cin >> source;
                graph.bfs(graph.adjacency_list, source);
                break;
            case 3:
                break;
            default:
                cout << "Enter a valid Number!!" << endl;
                break;
            }
            break;
        case 2:
            int choice3;
            cout << "1-Add Edge" << endl << "2-Update Edge" << endl << "3-Remove Edge" << endl << "4-Go back to Main Menu" << endl;
            cin >> choice3;
            switch (choice3)
            {
            case 1:
                cout << "Enter the source you want to edit:" << endl;
                cin >> source;
                cout << "Enter the destination you want to edit:" << endl;
                cin >> destination;
                graph.addEdge(source, destination, transport);
                break;
            case 2:
                cout << "Enter the source you want to edit:" << endl;
                cin >> source;
                cout << "Enter the destination you want to edit:" << endl;
                cin >> destination;
                graph.updateEdge(source, destination);
                break;
            case 3:
                cout << "Enter the source you want to edit:" << endl;
                cin >> source;
                cout << "Enter the destination you want to edit:" << endl;
                cin >> destination;
                graph.removeEdge(source, destination);
                break;
            case 4:
                break;
            default:
                cout << "Enter a valid Number!!" << endl;
                break;
            }

            break;
        
        case 3:
        {  bool complete = graph.CompleteGraph(graph.adjacency_list);
        if (complete == true)
        {
            cout << "Complete Graph" << endl;
        }
        else
        {
            cout << "Not Complete Graph" << endl;
        }
        break;
        }
        case 4:
            float budget;
            cout << "Enter the source you want to edit:" << endl;
            cin >> source;
            cout << "Enter the destination you want to edit:" << endl;
            cin >> destination;
            cout << "Enter the Max budget you want to pay:" << endl;
            cin >> budget;
            graph.findPaths(source, destination, budget, graph.adjacency_list);
            break;
        case 5:
            flag = false;
            break;
        }
    }
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
void Graph::bfs(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, string source) {
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
void Graph::dfs(unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, string source)
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
    cout<< endl;
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
void Graph::findPaths(string source, string destination, int budget, unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list) {
    unordered_set<string> visited;
    vector<string> path;
    vector<string> transportUsed;
    vector<pair<float, string>> paths;
    findPathsHelper(source, destination, budget, 0, adjacency_list, visited, path, transportUsed, paths);
    sort(paths.begin(), paths.end());

    for (const auto& p : paths) {
        cout << p.first << " " << p.second << endl;
    }

}
void Graph::findPathsHelper(string source, string destination, int budget, int currentCost, unordered_map<string, list<pair<string, Transporatations>>>& adjacency_list, unordered_set<string>& visited, vector<string>& path, vector<string>& transportUsed, vector<pair<float, string>>& paths) {
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
                    findPathsHelper(next_vertex, destination, budget, currentCost + trans.VechilePrice, adjacency_list, visited, path, transportUsed, paths);
                    transportUsed.pop_back();
                }
            }
        }
        visited.erase(source);
    }
    path.pop_back();
}





