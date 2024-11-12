//EXP 5: Dijkstra's algorithm
// Also calculating the time complexity and taking user input
#include <iostream>
#include <chrono>
#define MAX 100
#define INF 999999 // Define a large value to represent infinity
using namespace std;
using namespace std::chrono;

// Function to print the path from the source to the destination
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    cout << parent[j] << " - " << j << endl;
}

// Dijkstra's algorithm to find the shortest path
void dijkstra(int graph[MAX][MAX], int V, int src, int dest) {
    int dist[MAX];    // Array to hold the shortest distance from src to i
    bool visited[MAX]; // Array to mark visited vertices
    int parent[MAX];  // Array to hold the parent of each vertex

    // Initialize distance, visited, and parent arrays
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1; // Initialize parent array
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INF, min_index;
        // Find the vertex with the minimum distance from the set of unvisited vertices
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        int u = min_index;
        visited[u] = true;

        if (u == dest) break; // If we reached the destination, no need to continue

        // Update the distance of adjacent vertices of the selected vertex
        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // Set the parent of v to u
            }
    }

    // Check if a path exists between the source and destination
    if (dist[dest] == INF) {
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
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Remove this line if the graph is directed
    }
    int src, dest;
    cout << "Enter the source vertex: ";
    cin >> src;
    cout << "Enter the destination vertex: ";
    cin >> dest;
    
    auto start = high_resolution_clock::now();	// Start time measurement
    dijkstra(graph, V, src, dest);
    auto stop = high_resolution_clock::now();	// End time measurement
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by Dijkstra's algorithm: " << duration.count() << " microseconds" << endl;
    return 0;
}




// using limit
/*
#include <iostream>
#include <limits.h>
#include <chrono>
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
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Remove this line if the graph is directed
    }
    int src, dest;
    cout << "Enter the source vertex: ";
    cin >> src;
    cout << "Enter the destination vertex: ";
    cin >> dest;
    
    auto start = high_resolution_clock::now();	// Start time measurement
    dijkstra(graph, V, src, dest);
    auto stop = high_resolution_clock::now();	// End time measurement
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by Dijkstra's algorithm: " << duration.count() << " microseconds" << endl;
    return 0;
}
*/


// vertex=11; edge=22
/* input:0 1 1
1 2 9
2 3 1
0 8 8
1 8 7
2 8 2
2 9 4
2 10 3
8 9 1
9 10 6
10 4 2
3 10 1
3 4 4
0 7 2
8 7 6
8 6 5
9 6 3
10 6 9
10 5 7
4 5 9
7 6 1
6 5 2 */
