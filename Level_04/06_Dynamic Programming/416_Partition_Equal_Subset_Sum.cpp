// https://leetcode.com/problems/partition-equal-subset-sum/description/
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
// {1, 5, 11, 5}
int dp[210][20010];
bool solve(int i, int sum, vector<int> &num)
{
    if (sum == 0)
        return true;
    if (i < 0)
        return false;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    bool flag = solve(i - 1, sum, num);
    if (sum - num[i] >= 0)
        flag |= solve(i - 1, sum - num[i], num);
    return dp[i][sum] = flag;
}
bool canPartition(vector<int> &nums)
{
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    if (sum & 1)
        return false;
    int sz = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(sz - 1, sum / 2, nums);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vi arr = {1, 5, 11, 5};
    cout << ((canPartition(arr) == 1) ? "true" : "false") << nline;
    return 0;
}