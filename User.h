#pragma once

#include <iostream>
#include <fstream>
#include <string>

    using namespace std;

    class User {
    public:
        string fname;
        string lname;
        string email;
        string password;
        string phoneNumber;
        int age;

    public:
        User(); // Constructor
        void signUp(); // Sign up a new user
        bool login(); // Log in an existing user
    };

