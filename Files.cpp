#include "Files.h"
#include<iostream>
#include <fstream> // For file stream operations
#include <string>
#include<sstream>
#include<unordered_map>
#include "Edge.h"
#include"Graph.h"
#include"User.h"
#include<list>
#include<vector>

using namespace std;

Files::Files() {};


//void readfiles() {
//    if (inputFile.is_open()) {
//        cout << "Unable to open file" <<endl;
//      // or handle the error in your own way
//    }
//    string line;
//    while (getline(inputFile, line)) {
//        // Process each line here
//       cout << line <<endl; // Print each line to the console, for example
//    }
//}

    
unordered_map<string, list<pair<string, Edge>>>Files:: readTransportationData(string &filename)
{
    ifstream graphfile(filename);
    if (!graphfile.is_open())
    {
        cout << "error, opening file" << endl;
        return{};
    }
    int numOfRoutes;
    graphfile >> numOfRoutes;
    unordered_map < string, list<pair<string, Edge >>> routes;
    string line;
    getline(graphfile, line);

    while (getline(graphfile, line))
    {
        istringstream readline(line);//reads one line from the file
        string source, destination;
        readline >> source >> destination;
        string vehicleName;
        float price;
        Edge e;
        while (readline >> vehicleName >> price)
        {
            e.transportations.push_back({ vehicleName, price });
        }
        routes[source].push_back({ destination, e });
    }
    graphfile.close();
    return routes;


}
void Files::WriteTransportationData(unordered_map< string, list<pair<string, Edge>>> adjacentlist, string& filename)
{
    ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    // Write the number of routes at the beginning of the file
    outputFile << adjacentlist.size() << endl;

    // Iterate through the adjacency list and write data to the file
    for (const auto& entry : adjacentlist)
    {
        const string& source = entry.first;
        const list<pair<string, Edge>>& destinations = entry.second;

        // Write source node
        outputFile << source << " ";

        // Write destination nodes and associated transportation data
        for (const auto& destination : destinations)
        {
            const string& dest = destination.first;
            const Edge& edge = destination.second;

            // Write destination node
            outputFile << dest << " ";

            // Write transportation data
            for (const auto& transportation : edge.transportations)
            {
                outputFile << transportation.Vechilename << " " << transportation.VechilePrice << " ";
            }
            outputFile << endl; // End of transportation data for this destination
        }
    }

    outputFile.close();
}
    




















