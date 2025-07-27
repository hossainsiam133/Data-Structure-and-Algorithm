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
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first > p2.first) return 1;
    else if(p1.first == p2.first) return (p1.second < p2.second);
    return 0;
}
int main()
{
    Fast;
    vector<pair<int, int>> v = {{4, 143}, {3, 120}, {4, 500}, {1, 20}};
    sort(v.begin(),v.end(),cmp);
    for(auto it : v) cout<< it.first << ' ' << it.second << nline;
    return 0;
}