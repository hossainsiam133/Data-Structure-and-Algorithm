// https://atcoder.jp/contests/dp/tasks/dp_g
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
int N, M;
const int MX = 1e5 + 10;
vector<int> edge[MX];
int vis[MX];
int solve(int u)
{
    if (vis[u] != -1)
        return vis[u];
    int cnt = 0;
    for (auto v : edge[u])
    {
        cnt = max(cnt, solve(v) + 1);
    }
    return vis[u] = cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    // memset(edge, 0, sizeof(edge));
    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    int mx = -1;
    for (int i = 1; i <= N; i++)
    {
        // cout << i << ' ' << solve(i) << nline;
        mx = max(mx, solve(i));
    }
    cout << mx << nline;
    return 0;
}