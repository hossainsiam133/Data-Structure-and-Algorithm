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
// Way 1
map<int, int> NumOfDivisors(int n)
{
    vector<int> primeNum;
    map<int, int> Divisors;
    for (auto it : primes)
    {
        if (1LL * it * it > n)
            break;
        if (n % it == 0)
        {

            while (n % it == 0)
            {
                // primeNum.push_back(it);
                Divisors[it]++;
                n /= it;
            }
        }
    }
    if (n > 1)
        Divisors[n]++;
    return Divisors;
}
// Way 2
ll NOD(ll n)
{
    ll nod = 1;
    for (auto it : primes)
    {
        if (1LL * it * it > n)
            break;
        if (n % it == 0)
        {
            ll cnt = 0;
            while (n % it == 0)
            {
                // primeNum.push_back(it);
                cnt++;
                n /= it;
            }
            nod *= (cnt + 1);
        }
    }
    if (n > 1)
        nod *= 1LL * 2;
    return nod;
}
int main()
{
    Fast;
    int limit = 1e7;
    seive(limit);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << NOD(n) << nline;
    }
    // map<int, int> ans = NumOfDivisors(n);
    // ll num = 1;
    // for (auto u : ans)
    // {
    //     num *= (u.second + 1);
    // }
    // cout << num << nline;
    return 0;
}