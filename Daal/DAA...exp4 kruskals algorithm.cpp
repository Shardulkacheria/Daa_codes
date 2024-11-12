//EXP 4: Kruskal's algorithm
// taking user inout for the number of edges, vertices, and their weight
/* Example:-
let vertices=4
edges=5
input for source, destination, weight
0 1 10
0 2 6
0 3 5 
1 3 15
2 3 4
*/
// EXP 4: Kruskal's algorithm
// Taking user input for the number of edges, vertices, and their weight
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define MAX 100 

struct Edge {
    int src, dest, weight;
};

void swapEdges(Edge &a, Edge &b) {  //called in sortEdges function to rearrange the edges in ascending order (small to big)
    Edge temp = a;
    a = b;
    b = temp;
}

// A simple function to sort edges based on their weight
void sortEdges(Edge edges[], int E) {   //bubble sort
    for (int i = 0; i < E-1; i++) {
        for (int j = 0; j < E-i-1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                swapEdges(edges[j], edges[j+1]);
            }
        }
    }
}

//uses path compression to find the "leader" (or root) of the subset a vertex belongs to
/*This line checks if i is the root of its subset by comparing parent[i] to i.
If parent[i] == i, then i is its own parent, meaning it is the root of its component. In this case, we simply return i.
If parent[i] != i, then i is not the root, and we need to find the root of i by following its parent pointers.*/
int findParent(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = findParent(parent, parent[i]);
    return parent[i];
}

//uses the union by rank method to combine two subsets
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;   //The root with the smaller rank (rootX here) becomes a child of the root with the larger rank (rootY)
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++; 
        //If both roots have the same rank, we make one the parent of the other 
		//(in this case, rootX becomes the parent of rootY) and increase the rank of rootX by 1.
    }
}

void kruskalMST(int V, int E, Edge edges[]) {
    Edge result[MAX]; // To store the resulting MST
    int parent[MAX], rank[MAX] = {0};
    int totalWeight = 0;
    int resultSize = 0;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    sortEdges(edges, E);

    for (int i = 0; i < E; i++) {
        int x = findParent(parent, edges[i].src);
        int y = findParent(parent, edges[i].dest);

        if (x != y) {
            result[resultSize++] = edges[i];
            unionSets(parent, rank, x, y);
            totalWeight += edges[i].weight;
        }
    }

    cout << "Edges in the MST:\n";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Edge edges[MAX];

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    auto start = chrono::high_resolution_clock::now();  // Start measuring time
    kruskalMST(V, E, edges);
    auto stop = chrono::high_resolution_clock::now();   // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "\nTime taken by Kruskal's algorithm: " << duration.count() << " microseconds" << endl;

    return 0;
}



// code using vector and algorithm
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>  // To measure execution time
using namespace std;
using namespace std::chrono;

struct Edge {
    int src, dest, weight;  // source vertex, destination vertex, weight of edge
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class Graph {
    int V;  // Number of vertices
    vector<Edge> edges;  // Vector of all edges

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    int findParent(vector<int> &parent, int i) {
        if (parent[i] != i)
            parent[i] = findParent(parent, parent[i]);
        return parent[i];
    }

    void unionSets(vector<int> &parent, vector<int> &rank, int x, int y) {
        int rootX = findParent(parent, x);
        int rootY = findParent(parent, y);

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    void kruskalMST() {
        vector<Edge> result;
        vector<int> parent(V), rank(V, 0);
        int totalWeight = 0; // To accumulate the total weight of the MST

        for (int i = 0; i < V; i++) parent[i] = i;

        sort(edges.begin(), edges.end(), compareEdges);

        for (const Edge &edge : edges) {
            int x = findParent(parent, edge.src);
            int y = findParent(parent, edge.dest);

            if (x != y) {
                result.push_back(edge);
                unionSets(parent, rank, x, y);
                totalWeight += edge.weight; // Add the weight of the edge to the total weight
            }
        }

        cout << "Edges in the MST:\n";
        for (const Edge &e : result) {
            cout << e.src << " - " << e.dest << " : " << e.weight << endl;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;  // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V);

    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    auto start = chrono::high_resolution_clock::now();	// Start measuring time
    graph.kruskalMST();
    auto stop = chrono::high_resolution_clock::now();	// Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "\nTime taken by Kruskal's algorithm: " << duration.count() << " microseconds" << endl;

    return 0;
}

*/
