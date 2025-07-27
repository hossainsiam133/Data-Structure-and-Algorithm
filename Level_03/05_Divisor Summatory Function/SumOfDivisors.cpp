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
    int sq = sqrt(n);
    int SNOD = 0;
    for (int i = 1; i <= sq; i++)
    {
        SNOD += (n / i) - i;
    }
    SNOD *= 2;
    SNOD += sq;
    cout << SNOD << nline;
    return 0;
}