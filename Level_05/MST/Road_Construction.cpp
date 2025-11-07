// https://lightoj.com/problem/road-construction
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
#define nline '\n'
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
vector<int> par, sz;
int find_par(int u)
{
    if (par[u] == u)
        return u;
    return find_par(par[u]);
}
void Union(int u, int v)
{
    if (sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}
void solve(int test)
{
    cout << nline;
    int n;
    cin >> n;
    vector<pair<int, pair<int, int> > > edge;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        if (mp[s1] == 0)
            mp[s1] = mp.size();
        if (mp[s2] == 0)
            mp[s2] = mp.size();
        edge.PB(make_pair(w, make_pair(mp[s1], mp[s2])));
    }
    sort(all(edge));
    int nodes = mp.size();
    par.resize(nodes + 1);
    sz.resize(nodes + 1);
    for (int i = 1; i <= nodes; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
    int w = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int u = edge[i].S.F;
        int v = edge[i].S.S;
        int cost = edge[i].F;
        u = find_par(u);
        v = find_par(v);
        if (u != v)
        {
            Union(u, v);
            w += cost;
            cnt += 1;
        }
        // cout << edge[i].S.F << ' ' << edge[i].S.S << " " << edge[i].F << nline;
    }
    cout<< "Case " << test << ": ";
    if (cnt == nodes-1)
    cout<< w;
    else
    cout<< "Impossible";
}

int main()
{
    optimize();
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}