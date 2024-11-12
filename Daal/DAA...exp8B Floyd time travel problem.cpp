//EXP 8B: Floyd travel time problem
#include <iostream>
#include <limits.h>
#define INF 99999
using namespace std;

void printSolution(int d[][100], int V) {
    cout << "The shortest travel times between every pair of intersections (in minutes and seconds):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (d[i][j] == INF)
                cout << "INF\t";
            else {
                int minutes = d[i][j] / 60;
                int seconds = d[i][j] % 60;
                cout << minutes << "m " << seconds << "s\t";
            }
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][100], int V) {
    int d[100][100];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            d[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    // Print the shortest distance matrix
    printSolution(d, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100];

    cout << "Enter the travel time between vertices in minutes and seconds.\n";
    cout << "(If no direct path, enter -1 for both minutes and seconds.)\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                graph[i][j] = 0; // Distance to self is always 0
                continue;
            }
            int minutes, seconds;
            cout << "Enter travel time from vertex " << i + 1 << " to " << j + 1 << " (minutes seconds): ";
            cin >> minutes >> seconds;

            if (minutes == -1 && seconds == -1) {
                graph[i][j] = INF; // No direct path
            } else {
                graph[i][j] = minutes * 60 + seconds; // Converting to seconds
            }
        }
    }

    floydWarshall(graph, V);

    return 0;
}

