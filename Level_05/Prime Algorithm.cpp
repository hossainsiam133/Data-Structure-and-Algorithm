#include <bits/stdc++.h>
using namespace std;

#define V 6
#define INF INT_MAX

void printMst(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) { 
        parent[0] == -1;
        cout << parent[i] + 1 << " - " << i + 1 << "\t" << graph[i][parent[i]] << endl;
    }
}

int MinWeightVertex(int key[], int mstSet[]) {
    int mini = INF, Vertex = -1;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && key[i] < mini) {
            mini = key[i];
            Vertex = i;
        }
    }
    return Vertex;
}

void Prime(int graph[V][V]) {
    int mstSet[V];
    int parent[V];
    int key[V];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1; 
    
    for (int count = 0; count < V - 1; count++) {
        int u = MinWeightVertex(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMst(parent, graph);
}

int main() {
    int Graph[V][V] = {
        {0, 4, 6, 0, 0, 0},
        {4, 0, 6, 3, 4, 0},
        {6, 6, 0, 1, 0, 0},
        {0, 3, 1, 0, 2, 3},
        {0, 4, 0, 2, 0, 7},
        {0, 0, 7, 3, 7, 0}};
    Prime(Graph);
    return 0;
}
