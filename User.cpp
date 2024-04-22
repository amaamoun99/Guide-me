//#include "User.h"
//#include<iostream>
//#include<sstream>
//#include<fstream>
//#include<cctype>
//
//using namespace std;
//User::User() {}
//
//void User::signUp() {
//    int attemps = 100;
//    ofstream file("person.txt");
//    if (file.is_open()) {
//        cout << "Enter First Name: ";
//        cin >> fname;
//        cout << "Enter Last Name: ";
//        cin >> lname;
//        while (attemps > 0) {
//            cout << "Enter Email: ";
//            cin >> email;
//            if (email.size() <= 10 || (email.substr(email.size() - 10) != "@gmail.com" && email.substr(email.size() - 10) != "@yahoo.com")) {
//                cout << "Invalid email format! Email must end with @gmail.com or @yahoo.com" << endl;
//              
//                attemps--;
//            }
//
//            else {
//                break;
//            }
//        }
//        cout << "Enter Password: ";
//        cin >> password;
//        do {
//            cout << "Enter Phone Number (11 digits): ";
//            cin >> phoneNumber;
//            if (phoneNumber.length() != 11) {
//                cout << "Invalid phone number length! Phone number must have 11 digits." << endl;
//                continue;
//            }
//            bool validPhoneNumber = true;
//            for (char c : phoneNumber) {
//                if (!isdigit(c)) {
//                    validPhoneNumber = false;
//                    break;
//                }
//            }
//            if (!validPhoneNumber) {
//                cout << "Invalid phone number format! Phone number must contain only digits." << endl;
//                continue;
//            }
//            break;
//        } while (true);
//
//        cout << "Enter Age: ";
//        cin >> age;
//        if (age < 18) {
//            cout << "parental guideness is a must ";
//        }
//
//        file << fname << "," << lname << "," << email << "," << password << "," << phoneNumber << "," << age << endl;
//        cout << "User registered successfully!" << endl;
//        file.close();
//    }
//    else {
//        cerr << "Error: Unable to open file!" << endl;
//    }
//}
//
//
//
//bool User::login() {
//    ifstream file("person.txt");
//    if (file.is_open()) {
//        string userEmail, userPassword;
//        int trials = 3;
//        while (trials > 0) {
//            cout << "Enter Email: ";
//            cin >> userEmail;
//            cout << "Enter Password: ";
//            cin >> userPassword;
//            string line;
//
//         /*   file.clear();
//            file.seekg(0);*/
//            while (getline(file, line)) {
//                istringstream iss(line);
//                string emailFromFile, passwordFromFile;
//                getline(iss, fname, ',');
//                getline(iss, lname, ',');
//                getline(iss, emailFromFile, ',');
//                getline(iss, passwordFromFile, ',');
//                iss >> phoneNumber;
//                iss.ignore(); // Ignore the comma
//                iss >> age;
//                if (emailFromFile == userEmail && passwordFromFile == userPassword) {
//                    cout << "Login successful!" << endl;
//                    file.close();
//                    return true;
//                }
//            }
//            cout << "Invalid email or password! " << trials - 1 << " trials left" << endl;
//            trials--;
//        }
//        cout << "You have exceeded the maximum number of login attempts. Please sign up." << endl;
//        signUp();
//        file.close();
//    }
//    else {
//        cerr << "Error: Unable to open file!" << endl;
//    }
//    return false;
//}
