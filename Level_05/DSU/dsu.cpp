#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define nline "\n"
#define Yes cout << "YES\n"
#define No cout << "NO\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second

int par[123];
int find_par(int u)
{
    if (par[u] == u)
        return u;
    return find_par(par[u]);
}
void Union(int u, int v)
{
    par[v] = u;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        int uR = find_par(u);
        int vR = find_par(v);
        if (uR != vR)
        {
            Union(u, v);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(par[i] == i) cout<< i << nline;
    }
    return 0;
}