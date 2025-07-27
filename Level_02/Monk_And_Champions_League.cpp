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

int main()
{
    Fast;
    int n, p;
    cin >> n >> p;
    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    ll sum = 0;
    for (int i = 0; i < p; i++)
    {
        sum = sum + q.top();
        int top = q.top();
        q.pop();
        q.push(top - 1);
    }
    cout<< sum << nline;
    return 0;
}