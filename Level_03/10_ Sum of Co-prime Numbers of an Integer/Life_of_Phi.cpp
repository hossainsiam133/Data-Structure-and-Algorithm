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

const int mx = 1e6 + 123;
bitset<mx> isPrime;
vector<int> primes;
void seive(int N)
{
    isPrime[2] = true;
    for (int i = 3; i <= N; i += 2)
    {
        isPrime[i] = true;
    }
    for (int i = 3; i * i <= N; i += 2)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= N; j += i)
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
int phi[mx];
int main()
{
    Fast;
    int limit = 1e6;
    seive(limit);
    for (int i = 1; i <= limit; i++)
    {
        phi[i] = i;
    }
    for (auto p : primes)
    {
        for (int i = p; i <= limit; i += p)
        {
            phi[i] /= p;
            phi[i] *= (p - 1);
        }
    }
    // for (int i = 1; i <= 14; i++)
    // {
    //     cout << phi[i] << ' ';
    // }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll phi_sum = (1LL * phi[n] * n) / 2;
        ll tot_sum = (1LL * n * (n - 1)) / 2;
        cout << tot_sum - phi_sum << nline;
    }
    return 0;
}