// https://leetcode.com/problems/number-of-provinces/description/
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
vi par;
vi sz;
int find_par(int u)
{
    if (par[u] == u)
        return u;
    return par[u] = find_par(par[u]);
}
void Union(int u, int v)
{
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    par[u] += par[v];
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    sz.resize(n, 1);
    for (int i = 0; i < n; i++)
    {
        par.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (isConnected[i][j])
            {
                int ur = find_par(i);
                int vr = find_par(j);
                if (ur != vr)
                {
                    Union(ur, vr);
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (par[i] == i)
            cnt += 1;
    }
    return cnt;
    // cout << cnt << nline;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vi> v = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(v) << nline;
    return 0;
}
