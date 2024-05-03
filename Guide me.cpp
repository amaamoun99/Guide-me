#include "Files.h"
#include <iostream>
#include <unordered_map>
#include <list>
#include <utility> // for std::pair
#include "Transporatations.h" // Assuming Edge.h is properly defined
#include <vector>
#include"Graph.h"
#include"User.h"

using namespace std;

void main() {
    Files f;
    Graph g;
    Transporatations e;
    /*g.addEdge("Sinai", "Paris", e);
    g.updateEdge("Sinai", "Paris");*/
    g.displayAdjacentlist();
    string filename = "Graphdata.txt";
    f.WriteTransportationData(g.adjacency_list, filename);
  /*  Files f2;
    vector<User> users = f2.readUserData("person.txt");
    User u;
    u.signUp(users);
    u.UserMenu(users);

    string file = "person.txt";
    f2.writeUserData(file, users);*/
    string x = "Cairo";
    g.bfs(g.adjacency_list, x);
    g.dfs(g.adjacency_list, x);

    cout << g.CompleteGraph(g.adjacency_list);
}