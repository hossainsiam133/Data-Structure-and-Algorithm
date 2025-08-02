#include <bits/stdc++.h>
using namespace std;
#define V 6
#define INF INT_MAX

int findMinDistence(int distance[], int visited[])
{
    int min = INF, MinIndex;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && distance[i] <= min)
        {
            min = distance[i];
            MinIndex = i;
        }
    }
    return MinIndex;
}
void diakstra(int graph[V][V], int start)
{
    int distence[V];
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        distence[i] = INF;
        visited[i] = 0;
    }
    distence[start] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinDistence(distence, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] != INF && distence[u] != INF && distence[u] + graph[u][v] < distence[v])
            {
                distence[v] = distence[u] + graph[u][v];
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (distence[i] == INF)
        {
            cout << i << "\tINF" << endl;
        }
        else
            cout << i << "\t" << distence[i] << endl;
    }
}

int main()
{
    int Graph[V][V] = {
        {0, 2, 4, INF, INF, INF},
        {INF, 0, 1, 7, INF, INF},
        {INF, INF, 0, INF, 3, INF},
        {INF, INF, INF, 0, INF, 1},
        {INF, INF, INF, 2, 0, 5},
        {INF, INF, INF, INF, INF, 0}};
    int start = 0;
    diakstra(Graph, start);
    return 0;
}