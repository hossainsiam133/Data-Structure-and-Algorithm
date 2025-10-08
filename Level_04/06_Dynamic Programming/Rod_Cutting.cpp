// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define nline "\n"
#define Yes cout << "YES\n"
#define No cout << "NO\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second
int n;
int dp[1010];
int solve(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int mx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (len - i >= 0)
            mx = max(mx, solve(len - i, prices) + prices[i - 1]);
    }
    return dp[len] = mx;
}
int cutRod(vector<int> &price)
{
    n = price.size();
    memset(dp, -1, sizeof(dp));
    return solve(n, price);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vi a = {3, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(a) << nline;
    return 0;
}