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
    int n;
    cin >> n;
    set<int> multiplicand;
    for (int i = 1; i <= n; i++)
    {
        multiplicand.insert(__gcd(i, n));
    }
    for (int it : multiplicand)
    {
        cout << it << ' ';
    }
    return 0;
}