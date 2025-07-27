// https://vjudge.net/problem/uva-762
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

map<string, vector<string>> adj;
map<string, int> level;
map<string, string> parent;
void dfs(string s)
{
    level.clear();
    parent.clear();
    level[s] = 1;
    queue<string> q;
    q.push(s);
    while (!q.empty())
    {
        string u = q.front();
        q.pop();
        for (string v : adj[u])
        {
            if (level[v] == 0)
            {
                level[v] = level[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
int main()
{
    Fast;
    int n;
    bool line = false;
    while (cin >> n)
    {
        if (line)
            cout << nline;
        line = true;
        // if (n == 0)
        //     break;
        adj.clear();
        for (int i = 0; i < n; i++)
        {
            string u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string s, t;
        cin >> s >> t;
        dfs(s);
        if (level[t] == 0)
        {
            cout << "No route" << nline;
            continue;
        }
        vector<pair<string, string>> ans;
        while (!parent[t].empty())
        {
            ans.push_back({parent[t], t});
            t = parent[t];
        }
        reverse(ans.begin(), ans.end());
        for (auto it : ans)
        {
            cout << it.first << ' ' << it.second << nline;
        }
    }
    return 0;
}