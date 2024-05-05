#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

class User {
public:

    string username;
    string password;
    vector<User>users;
public:
    User();// 
    User(const string& username, const string& password);
    void signUp(vector<User>& users);
    void login(vector<User>& users);
    void UserMenu(vector<User>& users);
    void StartProgram();
};

