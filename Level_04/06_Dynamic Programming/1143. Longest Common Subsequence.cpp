// https://leetcode.com/problems/longest-common-subsequence/description/
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
int dp[1010][1010];
int solve(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = solve(i - 1, j, s1, s2);
    ans = max(ans, solve(i, j - 1, s1, s2));
    ans = max(ans, solve(i - 1, j - 1, s1, s2) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}
int longestCommonSubsequence(string text1, string text2)
{
    memset(dp, -1, sizeof(dp));
    return solve(text1.size() - 1, text2.size() - 1, text1, text2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestCommonSubsequence(s1, s2) << nline;
    return 0;
}