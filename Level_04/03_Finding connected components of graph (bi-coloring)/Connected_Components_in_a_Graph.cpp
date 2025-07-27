#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(), (a).end()
#define mid(l, r) ((r + l) / 2)

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define optimize()                \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
const int mx = 1e6 + 123;
bool vis[mx];
vector<int> adj[mx];
int mxVar = 0;
void dfs(int u)
{
    vis[u] = 1;
    mxVar = mxVar + 1;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    return;
}
void solve()
{
    int n, e;
    cin >> n >> e;
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    int mxConCom = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            mxVar = 0;
            dfs(i);
            mxConCom = max(mxConCom, mxVar);
        }
    }
    cout << "Number of Connected Graph: " << cnt << endl;
    cout << "Maximum Vartex of ones Connected Graph is: " << mxConCom << endl;
}

int main()
{
    optimize();
    solve();
    return 0;
}