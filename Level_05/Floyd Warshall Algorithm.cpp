#include <iostream>
#include <vector>

using namespace std;

const int INF = 10000000; // A large number to represent infinity

void floydWarshall(vector<vector<int>> &dist, int V)
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int V = 5; // Number of bus stops
    vector<vector<int>> dist = {
        {0, 5, INF, 10, INF},
        {INF, 0, 3, INF, INF},
        {INF, INF, 0, 1, 2},
        {INF, INF, INF, 0, 4},
        {INF, INF, INF, INF, 0}};

    floydWarshall(dist, V);
    int bus_stops, pickup_point;
    cout << "Enter the Source Bus Stops and Pickup Point: ";
    cin >> bus_stops >> pickup_point;
    cout << "Minimum time required to reach your pickup point is: "
             << dist[min(bus_stops, pickup_point)][max(bus_stops, pickup_point)] << endl;
    return 0;
}