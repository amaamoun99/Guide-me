#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Transporatations.h"

// Forward declaration of User class
class User;

using namespace std;
class Files
{
	//ifstream inputFile("graph.txt");
public:
	Files();
	unordered_map< string, list<pair<string, Transporatations>>> readTransportationData(string filename);
	void WriteTransportationData(unordered_map<string, list<pair<string, Transporatations>>>& adjacentlist, string filename);
	 vector<User>readUserData(string file);
	 void writeUserData(string file, vector<User>& users);
};

