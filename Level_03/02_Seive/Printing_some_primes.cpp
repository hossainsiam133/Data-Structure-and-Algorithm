// Will work CF Compiler Machine
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

const int N = 1e8;
bitset<N> isPrime;
vector<int> primes;
void seive()
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
    for (int i = 3; i <= N; i+=2)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}
void Display()
{
    for (int i = 0; i <= primes.size(); i += 100)
    {
        cout << primes[i] << nline;
    }
}
int main()
{
    Fast;
    seive();
    Display();
    return 0;
}