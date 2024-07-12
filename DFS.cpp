#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Class representing a graph using adjacency lists
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency lists

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v�s list
    }

    // Depth First Search traversal
    void DFS(int start) {
        // Mark all the vertices as not visited
        vector<bool> visited(V, false);

        // Create a stack for DFS
        stack<int> stack;

        // Push the current node onto the stack and mark it as visited
        stack.push(start);
        visited[start] = true;

        while (!stack.empty()) {
            // Pop a vertex from stack and print it
            int current = stack.top();
            cout << current << " ";
            stack.pop();

            // Get all adjacent vertices of the popped vertex
            // If an adjacent vertex has not been visited, then push it to the stack
            for (int i : adj[current]) {
                if (!visited[i]) {
                    stack.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    // Create a graph given in the example
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal starting from vertex 2: ";
    g.DFS(2);
    cout << endl;

    return 0;
}
