///In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

const int mx = 1e5+123;
int h[mx], n;
int dp[mx];

int solve ( int i )
{
    if ( i == n ) return 0;
    if ( dp[i] != -1 ) return dp[i];

    int ret1 = 2e9, ret2 = 2e9;

    if ( i+1 <= n ) ret1 = abs ( h[i] - h[i+1] ) + solve ( i+1 );
    if ( i+2 <= n ) ret2 = abs ( h[i] - h[i+2] ) + solve ( i+2 );

    dp[i] = min ( ret1, ret2 );
    return dp[i];
}


int main()
{

    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> h[i];

    memset ( dp, -1, sizeof ( dp ) );
    cout << solve ( 1 ) << endl;

    return 0;
}