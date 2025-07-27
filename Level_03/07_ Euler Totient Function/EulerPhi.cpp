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

const int N = 1e7 + 123;
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
ll EulerPhi(ll n)
{
    ll phi = n;
    for (auto it : primes)
    {
        if (1LL * it * it > n)
            break;
        if (n % it == 0)
        {
            while (n % it == 0)
            {
                n /= it;
            }
            phi /= it;
            phi *= (it - 1);
        }
    }
    if (n > 1)
    {
        phi /= n;
        phi*= (n-1);
    }
    return phi;
}
int main()
{
    Fast;
    int limit = 1e3;
    seive(limit);
    ll n;
    cin >> n; // Phi(1) = 0
    cout << EulerPhi(n) << nline;
    return 0;
}