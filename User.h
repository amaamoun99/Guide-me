#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "Graph.h"
using namespace std;

class User {
public:

    string username;
    string password;
    vector<User>users;
public:
    User();// 
    User(const string& username, const string& password);
    void signUp(vector<User>& users, Graph& graph);
    void login(vector<User>& users, Graph& graph);
    void UserMenu(vector<User>& users, Graph& graph);
    void StartProgram(Graph& graph);
};

