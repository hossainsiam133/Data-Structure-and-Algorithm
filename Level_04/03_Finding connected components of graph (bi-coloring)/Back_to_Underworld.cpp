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

const int mx = 2e4 + 123;
vi adj[mx];
bool vis[mx];
int tot, cnt1;
bool isNode[mx];
void dfs(int u, int col)
{
    vis[u] = 1;
    if (col == 1)
    {
        cnt1++;
        col = 2;
    }
    else
        col = 1;
    tot++;
    for (auto v : adj[u])
    {
        if (vis[v] == 0)
        {
            dfs(v, col);
        }
    }
    return;
}
int test = 0;
void solve()
{
    for (int i = 1; i <= 2e4; i++)
    {
        vis[i] = 0;
        adj[i].clear();
        isNode[i] = 0;
    }
    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        isNode[u] = 1;
        isNode[v] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= 2e4; i++)
    {

        if (isNode[i] == 1 && vis[i] == 0)
        {
            tot = 0, cnt1 = 0;
            dfs(i, 1);
            ans += max(cnt1, tot - cnt1);
        }
    }
    test++;
    cout << "Case " << test << ": " << ans << endl;
}

int main()
{
    optimize();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}