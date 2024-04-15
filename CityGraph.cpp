#include "CityGraph.h";
CityGraph::CityGraph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void CityGraph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void CityGraph::BFS(int s) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent vertex has not been visited, then mark it visited
        // and enqueue it
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}
