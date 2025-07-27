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

const int mx = 123;
bool isVisited[mx];
vector<int> adj[mx];
void dfs(int u)
{
    isVisited[u] = 1;
    cout << u << ' ';
    for (auto v : adj[u])
    {
        if (!isVisited[v])
        {
            dfs(v);
        }
    }
    return;
}
int main()
{
    Fast;
    //     1 -- 2
    //     |    |
    //     3    4 -- 7
    //     |    |
    //     5    8
    //     |
    //     6
    //    / \
//   9   10

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[4].push_back(7);
    adj[7].push_back(4);

    adj[4].push_back(8);
    adj[8].push_back(4);

    adj[3].push_back(5);
    adj[5].push_back(3);

    adj[5].push_back(6);
    adj[5].push_back(5);

    adj[6].push_back(9);
    adj[9].push_back(6);

    adj[6].push_back(10);
    adj[10].push_back(6);
    dfs(1);
    return 0;
}