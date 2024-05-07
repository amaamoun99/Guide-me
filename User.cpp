#include "User.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<cctype>
#include<vector>
#include"Graph.h"
#include"Files.h"
#include"Transporatations.h"


using namespace std;

User::User() {
    
}
User::User(const std::string& username, const std::string& password) : username(username), password(password) {
    
}

    

void User::StartProgram(Graph& graph, vector<User>&users)
{
    UserMenu(users,  graph);
}


void User::signUp(vector<User>& users, Graph& graph) {
    User u;
    cout << "Enter new username for signup: ";
    cin >> u.username;

    // Check if the username already exists
    bool usernameExists = false;
    for (const auto& user : users) {
        if (u.username == user.username) {
            usernameExists = true;
            break;
        }
    }

    // If the username exists, prompt the user to choose a different one
    if (usernameExists) {
        cout << "Username already exists. Please choose a different one.\n";
        signUp(users,graph); // Recursively call signUp to try again
        return;
    }

    cout << "Enter password for signup: ";
    cin >> u.password;
    cout << "Account created successfully.\n";

    users.push_back(u);
    u.login(users, graph);
    return;
}

//we will put the menu of the program and call it as a function


void User::login(vector<User>& users, Graph& graph){
    string input_username, input_password;
    int attempts = 3;
    bool flag = false;
    while (attempts > 0 && !flag) {
        cout << "Enter username: ";
        cin >> input_username;
        cout << "Enter password: ";
        cin >> input_password;

        for (auto it = users.begin(); it != users.end(); it++) {
            if (input_username == it->username && input_password == it->password) {
                cout << "login successfully!";
                flag = true;
                break;
            }
        }
        if (!flag) {
            attempts--;
            cout << "Invalid email or password. " << attempts << " attempts left\n\n";
        }
    }
    if (!flag) {
        cout << "You have exceeded the number of attempts. Please sign up.\n\n";
        signUp(users,graph);
        return;
    }
    
    // we will put the menu of the program and call it as a function
    graph.MainMenu(graph);
}

void User::UserMenu(vector<User>& users, Graph& graph) {
    int ans;
    User u;
    cout << "1- Login \n" << "2- Sign up to create new account \n";
    cin >> ans;
    switch (ans)
    {
    case 1:
        u.login(users,graph);
        
        break;

    case 2:
        u.signUp(users,graph);
        break;
    }
}
