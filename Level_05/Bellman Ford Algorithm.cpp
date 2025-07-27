#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline char(10)
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define Yes cout << "YES\n"
#define No cout << "NO\n"
#define print(v)           \
    for (auto &it : v)     \
    {                      \
        cout << it << ' '; \
    }                      \
    cout << endl;
#define INF INT_MAX
const int N = 8;
vector<int> dist(N, INF);


void bellman(int graph[N][N])
{
    dist[0] = 0;
    for (int k = 0; k < N - 1; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if (graph[i][j] == INF)
                    continue;
                if (dist[i] + graph[i][j] < dist[j])
                    dist[j] = dist[i] + graph[i][j];
            }
        }
    }
    for (int it : dist)
        cout << it << ' ';
    cout << nline;
}

int main()
{
    Fast;
    int graph[N][N] = {{INF, 1, 2, 5, INF, INF, INF, INF},
                   {INF, INF, INF, INF, 4, 11, INF, INF},
                   {INF, INF, INF, INF, 9, 5, 16, INF},
                   {INF, INF, INF, INF, INF, INF, 2, INF},
                   {INF, INF, INF, INF, INF, INF, INF, 18},
                   {INF, INF, INF, INF, INF, INF, INF, 13},
                   {INF, INF, INF, INF, INF, INF, INF, 2},
                   {INF, INF, INF, INF, INF, INF, INF, INF}};
    bellman(graph);
    return 0;
}