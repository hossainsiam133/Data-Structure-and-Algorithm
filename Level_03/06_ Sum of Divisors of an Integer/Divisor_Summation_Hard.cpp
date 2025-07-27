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

const int N = 1e8 + 123;
bitset<N> isPrime;
vector<int> primes;
void seive(int N)
{
    for (int i = 3; i <= N; i += 2)
    {
        isPrime[i] = true;
    }
    for (int i = 3; i <= sqrt(N); i += 2)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * 2; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}
ll SOD(ll n)
{
    ll snod = 1;
    for (auto it : primes)
    {
        if (1LL * it * it > n)
            break;
        if (n % it == 0)
        {
            ll a = 1;
            ll sum = 1;
            while (n % it == 0)
            {
                a *= it;
                sum += a;
                n /= it;
            }
            snod *= sum;
        }
    }
    if (n > 1)
    {
        snod *= (1 + n);
    }
    return snod;
}
int main()
{
    Fast;
    int limit = 1e8;
    seive(limit);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = SOD(n);
        cout << ans - n << nline;
    }
    return 0;
}