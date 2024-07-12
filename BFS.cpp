#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset
using namespace std;

const int MAX_VERTICES = 1000; // Maximum number of vertices

vector<int> adj[MAX_VERTICES]; // Adjacency list representation
bool visited[MAX_VERTICES];    // Visited array to keep track of visited vertices

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }

    memset(visited, false, sizeof(visited)); // Initialize visited array to false

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS Traversal starting from vertex " << startVertex << ": ";
    bfs(startVertex);
    cout << endl;

    return 0;
}
