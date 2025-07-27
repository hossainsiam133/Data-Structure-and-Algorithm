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
const int mx = 1e5 + 123;
vector<int> adJList[mx];
int main()
{
    Fast;
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adJList[u].push_back(v);
        adJList[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Adjacent List of " << i << " is: ";
        for (auto it : adJList[i])
            cout << it << ' ';
        cout << nline;
    }
    return 0;
}