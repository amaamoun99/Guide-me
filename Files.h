#pragma once
#include<iostream>
#include <fstream> // For file stream operations
#include <string>
#include<vector>
#include<unordered_map>
#include"Edge.h"
using namespace std;
class Files
{
	//ifstream inputFile("graph.txt");
public:
	Files();
	unordered_map< string, list<pair<string, Edge>>> readTransportationData(string &filename);
	 void WriteTransportationData(unordered_map< string, list<pair<string, Edge>>> adjacentlist, string& filename);
};

