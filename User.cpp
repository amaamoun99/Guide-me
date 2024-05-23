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
User::User(const string& username, const string& password) : username(username), password(password) {

}


void User::load()
{
    g.adjacency_list = readTransportationData("Graphdata.txt");
    users = readUserData("person.txt");
}


void User::StartProgram()
{
    load();
    UserMenu();
}


void User::UserMenu() {
    bool flag = true;
    while (flag)
    {
        system("cls");
        int ans;
        int consoleWidth = 120;
        int padding = (consoleWidth - 25) / 2;
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << string(padding, ' ') << "\t\tWelcome to Gudie Me\n"
            << string(padding, ' ') << "-------------------------------------\n"
            << string(padding, ' ') << "1- Login\n"
            << string(padding, ' ') << "2- Sign up to create new account \n"
            << string(padding, ' ') << "3- Exit Program\n"
            << string(padding, ' ') << "Choice:";
        cin >> ans;
        switch (ans)
        {
        case 1:
            system("cls");
            login();
            break;

        case 2:
            system("cls");
            signUp();
            break;
        case 3:
            flag = false;
            exit(0);
            break;
        default:
            cout << string(padding, ' ') << "Enter a valid number!\n";
            system("pause");
        }
        cout << "\n\n\n\n\n\n\n\n\n\n";
    }
}

void User::login() {
    system("cls");
    string input_username, input_password;
    int attempts = 3;
    bool flag = false;
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;

    while (attempts > 0 && !flag) {
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << string(padding, ' ') << "\t\t\tLogin\n"
            << string(padding, ' ') << "-------------------------------------\n";
        cout << string(padding, ' ') << "Enter username: ";
        cin >> input_username;
        cout << string(padding, ' ') << "Enter password: ";
        cin >> input_password;


        for (auto it = users.begin(); it != users.end(); it++) {
            if (input_username == it->username && input_password == it->password) {
                cout << string(padding, ' ') << "Logged In Successfully!\n";
                cout << string(padding, ' ') << system("pause");

                if (input_username == "admin" && input_password == "admin")
                {
                    
                    adminMenu();
                }
                flag = true;
                userMenu();
                break;
            }
        }
        if (!flag) {
            attempts--;
            cout << string(padding, ' ') << "Invalid email or password. " << attempts << " attempts left\n\n";
            cout << string(padding, ' ') << system("pause");
            system("cls");

        }
    }
    if (!flag) {
        cout << string(padding, ' ') << "You have exceeded the number of attempts. Please sign up.\n\n";
        cout << string(padding, ' ') << system("pause");
        signUp();
        return;
    }
}


void User::signUp() {
    system("cls");
    User u;
    int consoleWidth = 120;
    int padding = (consoleWidth - 25) / 2;
    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << string(padding, ' ') << "\t\t\tSign Up\n"
        << string(padding, ' ') << "-------------------------------------\n";

    cout << string(padding, ' ') << "Enter new username for signup: ";
    cin >> u.username;

    
    bool usernameExists = false;
    for (const auto& user : users) {
        if (u.username == user.username) {
            usernameExists = true;
            break;
        }
    }

   
    if (usernameExists) {
        cout << "\n\n\n\n";
        cout << string(padding, ' ') << "Username already exists. Please choose a different one.\n";
        cout << string(padding, ' ') << system("pause");
        signUp();
        return;
    }

    cout << string(padding, ' ') << "Enter password for signup: ";
    cin >> u.password;
    cout << "\n\n\n";
    cout << string(padding, ' ') << "Account created successfully!\n";
    cout << string(padding, ' ') << system("pause");

    users.push_back(u);
    login();
    return;
}

void User::adminMenu()
{
    system("cls");
    int choice;
    string source;
    string destination;
    Transporatations transport;

    while (true)
    {
        system("cls");
        int consoleWidth = 120;
        int padding = (consoleWidth - 25) / 2;
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << string(padding, ' ') << "\t\t\tMenu\n"
            << string(padding, ' ') << "-------------------------------------\n";


        cout << string(padding, ' ') << "1-Edit Graph\n"
            << string(padding, ' ') << "2-Display Adjaceny List\n"
            << string(padding, ' ') << "3-Check whether the graph is Complete or not\n"
            << string(padding, ' ') << "4-Exit Program\n"
            << string(padding, ' ') << "Choice:";
        cin >> choice;
        cout << string(padding, ' ') << system("pause");

        switch (choice)
        {
        case 1:
            while (true)
            {
                system("cls");
                bool flag = true;
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << string(padding, ' ') << "\t\t\tEdit Graph\n"
                    << string(padding, ' ') << "-------------------------------------\n";

                int choice3;

                cout << string(padding, ' ') << "1-Add Edge\n"
                    << string(padding, ' ') << "2-Update Edge\n"
                    << string(padding, ' ') << "3-Delete Edge\n"
                    << string(padding, ' ') << "4-Go Back to Menu\n"
                    << string(padding, ' ') << "Choice:";
                cin >> choice3;
                cout << system("pause");
                switch (choice3)
                {
                case 1:
                    system("cls");
                    cout << "\n\n\n\n\n\n\n\n\n\n";
                    cout << string(padding, ' ') << "\t\t\tAdd Edge\n"
                        << string(padding, ' ') << "-------------------------------------\n";
                    cout << string(padding, ' ') << "Enter the source you want to add:";
                    cin >> source;
                    cout << string(padding, ' ') << "Enter the destination you want to add:";
                    cin >> destination;
                    system("pause");
                    g.addEdge(source, destination);
                    cout << "\n\n";
                    cout << string(padding, ' ') << "Added Successfully!\n";
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    cout << "\n\n\n\n\n\n\n\n\n\n";
                    cout << string(padding, ' ') << "\t\t\tUpdate Edge\n"
                        << string(padding, ' ') << "-------------------------------------\n";
                    g.displayAdjacentlistforfunctions();
                    cout << string(padding, ' ') << "Enter the source you want to update:";
                    cin >> source;
                    cout << string(padding, ' ') << "Enter the destination you want to update:";
                    cin >> destination;
                    system("pause");
                    g.updateEdge(source, destination);
                    break;
                case 3:
                    system("cls");
                    cout << "\n\n\n\n\n\n\n\n\n\n";
                    cout << string(padding, ' ') << "\t\t\tRemove Edge\n"
                        << string(padding, ' ') << "-------------------------------------\n";
                    g.displayAdjacentlistforfunctions();
                    cout << string(padding, ' ') << "Enter the source you want to remove:";
                    cin >> source;
                    cout << string(padding, ' ') << "Enter the destination you want to remove:";
                    cin >> destination;
                    system("pause");
                    g.removeEdge(source, destination);
                    cout << "\n\n";
                    cout << string(padding, ' ') << "Removed Successfully!\n";
                    system("pause");
                    break;
                case 4:
                    adminMenu();
                    break;
                default:
                    cout << string(padding, ' ') << "\n\nEnter a valid Number!" << endl;
                }

            }
            break;
        case 2:
            system("cls");
            g.displayAdjacentlist();
            system("pause");
            adminMenu();
            break;
        case 3:
            {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << string(padding, ' ') << "\t\t\tComplete Graph\n"
                << string(padding, ' ') << "-------------------------------------\n";

            bool complete = g.CompleteGraph();
            if (complete == true)
            {
                cout << string(padding, ' ') << "Complete Graph" << endl;
            }
            else
            {
                cout << string(padding, ' ') << "Not Complete Graph" << endl;
            }
            system("pause");
            adminMenu();
            break;
        }
        case 4:
            save();
            break;
            return;
        }
        break;
    }
    StartProgram();
}

void User::userMenu()
{
    int choice;
    string source;
    string destination;
    bool flag = true;
    while (flag)
    {
        system("cls");
        int consoleWidth = 120;
        int padding = (consoleWidth - 25) / 2;
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << string(padding, ' ') << "\t\t\tMenu\n"
            << string(padding, ' ') << "-------------------------------------\n";


        cout << string(padding, ' ') << "1-Traverse the Graph\n"
            << string(padding, ' ') << "2-Find Route\n"
            << string(padding, ' ') << "3-Exit Program\n"
            << string(padding, ' ') << "Choice:";
        cin >> choice;
        system("pause");
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << string(padding, ' ') << "\t\tTraverse the Graph\n"
                << string(padding, ' ') << "-------------------------------------\n";

            int choice2;

            cout << string(padding, ' ') << "1-BFS\n"
                << string(padding, ' ') << "2-DFS\n"
                << string(padding, ' ') << "3-Go back to Main Menu\n"
                << string(padding, ' ') << "Choice:";
            cin >> choice2;
            switch (choice2) {

            case 1:
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << string(padding, ' ') << "\t\t\tBFS\n"
                    << string(padding, ' ') << "-------------------------------------\n";

                for (const auto& entry : g.adjacency_list) {

                    cout << string(padding, ' ') << "Source: " << entry.first << endl;
                }

                cout << string(padding, ' ') << "Enter the Source:";
                cin >> source;
                g.bfs(source);
                break;
            case 2:
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << string(padding, ' ') << "\t\t\tDFS\n"
                    << string(padding, ' ') << "-------------------------------------\n";

                for (const auto& entry : g.adjacency_list) {

                    cout << string(padding, ' ') << "Source: " << entry.first << endl;
                }

                cout << string(padding, ' ') << "Enter the Source:";
                cin >> source;
                g.dfs(source);
                break;
            case 3:
                system("pause");
                userMenu();
                break;
            default:
                cout << string(padding, ' ') << "Enter a valid Number!!" << endl;
                system("pause");
                break;
            }
            break;
        case 2:
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << string(padding, ' ') << "\t\tAMNY FY GRAPH\n"
                << string(padding, ' ') << "-------------------------------------\n";
            float budget;
            int i = 0;
            for (const auto& entry : g.adjacency_list) {

                cout << string(padding, ' ') << "Governorate " << i + 1 << ": " << entry.first << endl;
                i++;
            }
            cout << string(padding,' ') << "-------------------------------------\n";
            cout << string(padding, ' ') << "Enter the source you want:";
            cin >> source;
            cout << string(padding, ' ') << "Enter the destination you want:";
            cin >> destination;
            cout << string(padding, ' ') << "Enter the Max budget you want to pay:";
            cin >> budget;
            cout << string(padding, ' ') << "-------------------------------------\n";
            g.findPaths(source, destination, budget);
            break;
        }
        case 3:
            flag = false;
            save();
            StartProgram();
            break;
        }
    }
}


void User::save()
{
    writeUserData("person.txt", users);
    WriteTransportationData(g.adjacency_list, "Graphdata.txt");
}
