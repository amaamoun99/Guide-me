#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Files.h"
#include "Graph.h"

class User : public Files{
public:
    string username;
    string password;
    vector<User> users;
    Graph g;
public:
    User();
    User(const string& username, const string& password);
    void load();
    void StartProgram();
    void UserMenu();
    void login();
    void signUp();
    void adminMenu();
    void userMenu();
    void save();
};

