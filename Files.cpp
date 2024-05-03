#include "Files.h"
#include<iostream>
#include <fstream> // For file stream operations
#include <string>
#include<sstream>
#include<unordered_map>
#include "Transporatations.h"
#include"Graph.h"
#include"User.h"
#include<list>
#include<vector>
#include<unordered_set>

using namespace std;

Files::Files() {};


unordered_map<string, list<pair<string, Transporatations>>>Files::readTransportationData(string& filename)
{
    ifstream graphfile(filename);
    if (!graphfile.is_open())
    {
        cout << "error, opening file" << endl;
        return{};
    }
    int numOfRoutes;
    graphfile >> numOfRoutes;

    unordered_map < string, list<pair<string, Transporatations >>> routes;
    string line;
    getline(graphfile, line);

    while (getline(graphfile, line))
    {
        istringstream readline(line);//reads one line from the file
        string source, destination;
        readline >> source;
        readline.ignore();
        readline.ignore();
        readline >> destination;
        string vehicleName;
        float price;
        Transporatations e;
        while (readline >> vehicleName >> price)
        {
            e.transportations.push_back({ vehicleName, price });
        }
        routes[source].push_back({ destination, e });
        routes[destination].push_back({ source,e });
    }
    graphfile.close();
    return routes;


}
void Files::WriteTransportationData(unordered_map<string, list<pair<string, Transporatations>>>& adjacentlist, string& filename)
{
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    int totalEdges = 0;
    for (const auto& route : adjacentlist) {
        totalEdges += route.second.size();// Increment the total edges by the number of destinations for each source
    }

    totalEdges /= 2;

    outfile << totalEdges << endl; // Write the total number of edges

    unordered_set<string> writtenEdges; // Keep track of written edges

    for (const auto& route1 : adjacentlist) {
        for (const auto& dest1 : route1.second) {
            // Construct the edge key using source and destination
            string edgeKey = route1.first + " - " + dest1.first;
            // Check if the reversed edge exists in the written edges set
            string reversedEdgeKey = dest1.first + " - " + route1.first;
            if (writtenEdges.find(reversedEdgeKey) == writtenEdges.end()) {
                // Check if the edge has already been written
                if (writtenEdges.find(edgeKey) == writtenEdges.end()) {
                    outfile << route1.first << " - " << dest1.first << " ";
                    for (const auto& trans : dest1.second.transportations) {
                        outfile << trans.Vechilename << " " << trans.VechilePrice << " ";
                    }
                    outfile << endl;
                    // Mark the edge as written
                    writtenEdges.insert(edgeKey);
                }
            }
        }
    }
    outfile.close();
}

vector<User> Files::readUserData(string file) {
    vector <User> users;
    ifstream userfile(file);
    if (!userfile) {
        cout << "Error opening File\n";
    }
    string lineOfUser;
    while (getline(userfile, lineOfUser)) {
        stringstream ss(lineOfUser);
        string username, password;
        getline(ss, username, ',');
        getline(ss, password, ',');
        users.push_back(User(username, password));

    }
    userfile.close();
    return users;
}

void Files::writeUserData(string& file, vector<User>& users) {
    ofstream outfile(file, ios::out | ios::trunc);
    if (!outfile.is_open()) {
        cout << "Error opening file " << file << " for writing" << endl;
    }

    for (const auto& user : users)
    {
        outfile << user.username << "," << user.password << endl;
    }

    outfile.close();
}