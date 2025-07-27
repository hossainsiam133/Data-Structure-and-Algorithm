// https://vjudge.net/problem/uva-10004
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

const int mx = 212;
vector<int> adj[mx];
int col[mx];
bool bfs(int s)
{
    memset(col, -1, sizeof(col));
    col[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (col[v] == -1)
            {
                if (col[u] == 1)
                    col[v] = 2;
                else
                    col[v] = 1;
                q.push(v);
            }
            else if (col[u] == col[v])
                return false;
        }
    }
    return true;
}
int main()
{
    Fast;
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int l;
        cin >> l;
        for (int i = 0; i < mx; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < l; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (bfs(0))
            cout << "BICOLORABLE." << nline;
        else
            cout << "NOT BICOLORABLE." << nline;
    }
    return 0;
}