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
    Files f2;
    Graph g;
    User u;
    string filename = "Graphdata.txt";
    string file = "person.txt";
    u.StartProgram();

    
    
   

  
    
    
   
    f2.writeUserData(file, u.users);
    f.WriteTransportationData(g.adjacency_list, filename);
}