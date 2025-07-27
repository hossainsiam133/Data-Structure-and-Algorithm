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
const int MX = 1e6 + 123;
const int limit = 1e6;
ll Phi[MX], ans[MX];
void LCM_SUM()
{
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
        for (int j = i; j <= limit; j += i)
        {
            ans[j] += (Phi[i] * i);
        }
    }
}
int main()
{
    Fast;
    seive(limit);
    LCM_SUM();
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll val = ans[n] + 1;
        val *= n;
        val /= 2;
        cout << val << nline;
    }
    return 0;
}