//EXP 8: Floyd WARSHALL
#include <iostream>
#include <vector>
#define INF 99999
using namespace std;

void printSolution(int dist[][100], int V) {
    cout << "The following matrix shows the shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][100], int V) {
    int dist[100][100];
    // Initializing a new matrix to store the updated values
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
	// iterating through each row and column
	for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                	dist[i][j] = dist[i][k] + dist[k][j];	
				}
            }
        }
    }

    // Printing the matrix
    printSolution(dist, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100];

    cout << "Enter the adjacency matrix (use " << INF << " for no direct path):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);

    return 0;
}

