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

const int sz = 1e7 + 123;
bitset<sz> isPrime;
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

const int mx = 5e6 + 123;
unsigned ll Phi[mx];
int main()
{
    Fast;
    int limit = 5e6;
    seive(limit);
    for (int i = 1; i <= limit; i++)
    {
        Phi[i] = i;
    }
    for (auto p : primes)
    {
        for (int i = p; i <= limit; i += p)
        {
            Phi[i] /= p;
            Phi[i] *= (p - 1);
        }
    }
    for (int i = 1; i <= limit; i++)
    {
        Phi[i] = Phi[i] * Phi[i] + Phi[i - 1];
    }
    // for (int i = 2; i <= 6; i++)
    // {
    //     cout << Phi[i] << ' ';
    // }
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        int a, b;
        cin >> a >> b;
        cout << "Case " << test << ": " << Phi[b] - Phi[a - 1] << nline;
    }
    return 0;
}