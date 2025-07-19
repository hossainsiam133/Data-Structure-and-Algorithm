#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF INT_MAX

void Multistage(int graph[V][V], int stage)
{
    int cost[V];
    int path[V];
    int destiny = V - 1;

    cost[destiny] = 0;
    path[destiny] = destiny;

    for (int i = V - 2; i >= 0; i--)
    {
        int mini = INT_MAX;
        for (int j = i + 1; j < V; j++)
        {
            if (graph[i][j] != 0 && cost[j] + graph[i][j] < mini)
            {
                mini = cost[j] + graph[i][j];
                path[i] = j;
            }
        }
        cost[i] = mini;
    }
    cout << "Minimum Cost: " << cost[0] << endl;
    int curr = 0;
    cout << "Path: ";
    while (curr != destiny)
    {
        cout << curr+1 << "->";
        curr = path[curr];
    }
    cout << destiny+1 << endl;
}

int main()
{
    int Graph[V][V] = {
        {0, 2, 1, 0},
        {0, 0, 0, 3},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    int stage = 3;
    Multistage(Graph, stage);
    return 0;
}