#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 10;
int n, sz;
int w[123], p[123];
int dp[123][mx];

int solve(int i, int currW)
{
    if (i > n)
        return 0;
    if (dp[i][currW] != -1)
        return dp[i][currW];
    int ret1 = 0, ret2 = 0;
    if (currW + w[i] <= sz)
    {
        ret1 = p[i] + solve(i + 1, currW + w[i]);
    }
    ret2 = solve(i + 1, currW);
    return dp[i][currW] = max(ret1, ret2);
}

void reconstruct(int i, int currW)
{
    if (i > n)
        return;
    int best = solve(i, currW);
    if (currW + w[i] <= sz && best == p[i] + solve(i + 1, currW + w[i]))
    {
        cout << i << " ";
        reconstruct(i + 1, currW + w[i]);
    }
    else
    {
        reconstruct(i + 1, currW);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> sz;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> p[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0) << "\n";
    cout << "Path: ";
    reconstruct(1, 0);
    return 0;
}