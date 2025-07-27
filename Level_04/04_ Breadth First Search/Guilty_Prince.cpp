// https://lightoj.com/problem/guilty-prince
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
const int mx = 30;
char ch[mx][mx];
int vis[mx][mx];
int cnt;
int n, m;
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !vis[x1][y1] && ch[x1][y1] != '#')
        {
            dfs(x1, y1);
        }
    }
    return;
}
int test = 0;
void solve()
{
    cin >> m >> n;
    int xx, yy;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch[i][j];
            if (ch[i][j] == '@')
            {
                xx = i;
                yy = j;
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    dfs(xx, yy);
    test++;
    cout << "Case " << test << ": " << cnt << endl;
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