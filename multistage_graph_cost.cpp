#include <bits/stdc++.h>
using namespace std;
#define N 8
#define INF INT_MAX

void shortestDist(int graph[N][N], int src)
{

    // dist[i] is going to store shortest
    // distance from node i to node N-1.
    int distance[N];
    distance[N - 1] = 0;

    // Calculating shortest path for
    // rest of the nodes
    for (int i = N - 2; i >= 0; i--)
    {

        // Initialize distance from i to
        // destination (N-1)
        distance[i] = INF;
        for (int j = i; j < N; j++)
        {
            // Reject if no edge exists
            if (graph[i][j] == INF)
                continue;
            // We apply equation to distance to target through j.
            // and compare with minimum distance so far.
            distance[i] = min(distance[i], graph[i][j] +
                                               distance[j]);
        }
    }
    // The minimum distance stored in distance[] from node 0 to 7
    cout << "Minimum distance to visit node 7 is: " << distance[src] << endl;
}

int main()
{
    // Graph stored in the form of an
    // adjacency Matrix
    int graph[N][N] =
        {{INF, 1, 2, 5, INF, INF, INF, INF},
         {INF, INF, INF, INF, 4, 11, INF, INF},
         {INF, INF, INF, INF, 9, 5, 16, INF},
         {INF, INF, INF, INF, INF, INF, 2, INF},
         {INF, INF, INF, INF, INF, INF, INF, 18},
         {INF, INF, INF, INF, INF, INF, INF, 13},
         {INF, INF, INF, INF, INF, INF, INF, 2},
         {INF, INF, INF, INF, INF, INF, INF, INF}};

    // Printing the shortest path to go node sources to node 7
    // destination is 7
    int sources;
    cout << "Sources Node: ";
    cin >> sources;
    shortestDist(graph, sources);
    return 0;
}
