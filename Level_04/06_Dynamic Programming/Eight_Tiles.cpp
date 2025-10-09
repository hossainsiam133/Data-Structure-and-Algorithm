#include <bits/stdc++.h>
using namespace std;
int s[3][3] = {{1, 5, 6}, {7, 4, 8}, {3, 2, 0}};
int d[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
int solve(int i, int j)
{
    if (s == d)
        return 0;
    int cnt = -1;
    if (i - 1 >= 0)
    {
        swap(s[i][j], s[i - 1][j]);
        cnt = solve(i - 1, j) + 1;
    }
    if (i + 1 <= 2)
    {
        swap(s[i][j], s[i + 1][j]);
        cnt = solve(i + 1, j) + 1;
    }

    if (j - 1 >= 0)
    {
        swap(s[i][j], s[i][j - 1]);
        cnt = solve(i, j - 1) + 1;
    }

    if (j + 1 <= 2)
    {
        swap(s[i][j], s[i][j + 1]);
        cnt = solve(i, j + 1) + 1;
    }

    return cnt;
}
int main()
{
    //(arr,0,sizeof(arr));
    int blank_i = 2, blank_j = 2;
    cout << solve(blank_i, blank_j) << endl;
    return 0;
}
