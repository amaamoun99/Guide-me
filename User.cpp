#include "User.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include<cctype>
#include<vector>

using namespace std;

User::User() {}
User::User(const string& username, const string& password) : username(username), password(password) {}


void User::signUp(vector<User>& users) {
    User u;
    cout << "Enter new username for signup: ";
    cin >> u.username;
    cout << "Enter password for signup: ";
    cin >> u.password;
    bool flag = false;
    for (auto it = users.begin(); it != users.end(); it++) {
        if (username == it->username && password == it->password) {
            cout << "Login successful\n";
            flag = true;
            break;
        }
    }
    users.push_back(u);
}
    
    
    //we will put the menu of the program and call it as a function


void User::login(vector<User>& users) {
    string input_username, input_password;
    int attempts = 3;
    bool flag = false;
    while (attempts > 0 && !flag) {
        cout << "Enter username: ";
        cin >> input_username;
        cout << "Enter password: ";
        cin >> input_password;

        /*for (auto it = users.begin(); it != users.end(); it++) {
            if (input_username == it->username && input_password == it->password) {
                cout << "can't sign up as it aready exists\n";
                flag = true;
                login(users);
                break;
            }
        }
        if (!flag) {
            attempts--;
            cout << "Invalid email or password. " << attempts << " attempts left\n\n";
        }*/
    }
    if (!flag) {
        cout << "You have exceeded the number of attempts. Please sign up.\n\n";
        signUp(users);
    }
    // we will put the menu of the program and call it as a function
}
void User::UserMenu(vector<User>& users) {
    int ans;
    User u;
    cout << "1- Login \n" << "2- Sign up to create new account \n";
    cin >> ans;
    switch (ans)
    {
    case 1:
        u.login(users);
        break;

    case 2:
        u.signUp(users);
        break;
    }
}
