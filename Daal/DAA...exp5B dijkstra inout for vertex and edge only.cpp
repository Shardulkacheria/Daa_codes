//EXP 5B: Dijkstra's algorithm
// Also calculating the time complexity
// taking user input only for vertex and number of edges
#include <iostream>
#include <limits.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#define MAX 100

using namespace std;
using namespace std::chrono;

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    cout << parent[j] << " - " << j << endl;
}

void dijkstra(int graph[MAX][MAX], int V, int src, int dest) {
    int dist[MAX]; // Array to hold the shortest distance from src to i
    bool visited[MAX]; // Array to mark visited vertices
    int parent[MAX]; // Array to hold the parent of each vertex

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1; // Initialize parent array
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, min_index;

        // Find the minimum distance vertex from the set of vertices not yet processed
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }

        int u = min_index;
        visited[u] = true;

        if (u == dest) break; // If we reached the destination, no need to continue

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Set the parent of v to u
            }
    }

    if (dist[dest] == INT_MAX) {
        cout << "There is no path between vertex " << src << " and vertex " << dest << "." << endl;
    } else {
        cout << "Shortest distance from vertex " << src << " to vertex " << dest << " is: " << dist[dest] << endl;
        cout << "Edges in the shortest path:" << endl;
        printPath(parent, dest);
    }
}

int main() {
    int V, E;
    int graph[MAX][MAX] = {0};

    srand(time(0)); // Seed for random number generation

    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Generate random edges
    for (int i = 0; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        while (v == u) { // Ensure no self-loop
            v = rand() % V;
        }
        int w = rand() % 10 + 1; // Random weight between 1 and 10
        graph[u][v] = w;
        graph[v][u] = w; // Remove this line if the graph is directed
    }

    int src, dest;
    cout << "Enter the source vertex: ";
    cin >> src;
    cout << "Enter the destination vertex: ";
    cin >> dest;

    cout << "Generated graph edges with weights:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0) {
                cout << i << " - " << j << " : " << graph[i][j] << endl;
            }
        }
    }

    // Start time measurement
    auto start = high_resolution_clock::now();

    dijkstra(graph, V, src, dest);

    // End time measurement
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by Dijkstra's algorithm: " << duration.count() << " microseconds" << endl;

    return 0;
}

