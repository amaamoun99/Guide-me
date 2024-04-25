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
    }
    graphfile.close();
    return routes;


}
void Files::WriteTransportationData(unordered_map< string, list<pair<string, Transporatations>>> adjacentlist, string& filename)
{
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    int totalEdges = 0;
    for (const auto& route : adjacentlist) {
        totalEdges += route.second.size(); // Increment the total edges by the number of destinations for each source
    }

    outfile << totalEdges << endl; // Write the total number of edges

    for (const auto& route : adjacentlist) {
        for (const auto& dest : route.second) {
            outfile << route.first << " - " << dest.first << " ";
            for (const auto& trans : dest.second.transportations) {
                outfile << trans.Vechilename << " " << trans.VechilePrice << " ";
            }
            outfile << endl;
        }
    }
    outfile.close();
}