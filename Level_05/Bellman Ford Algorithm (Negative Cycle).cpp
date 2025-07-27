#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF INT_MAX

void Bellman(int graph[V][V], int start)
{
    int distence[V];
    for (int i = 0; i < V; i++)
    {
        distence[i] = INF;
    }
    distence[start] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] != INF && distence[u] != INF && distence[u] + graph[u][v] < distence[v])
                {
                    distence[v] = distence[u] + graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && distence[u] != INF &&
                distence[u] + graph[u][v] < distence[v]) {
                printf("Graph contains a negative-weight cycle\n");
                return;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (distence[i] == INF)
            printf("%d\t\tINF\n", i);
        else
            printf("%d\t\t%d\n", i, distence[i]);
    }
}

int main()
{
    int Graph[V][V] = {
       {0, 1, INF, INF},  // Vertex 0 to 1 with weight 1
    {INF, 0, -1, INF}, // Vertex 1 to 2 with weight -1
    {INF, INF, 0, -1}, // Vertex 2 to 3 with weight -1
    {-1, INF, INF, 0} 
        };
    int start = 0;
    Bellman(Graph, start);
    return 0;
}