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

int main()
{
    Fast;
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q;
    int x;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum+=x;
        q.push(sum);
        
    }
    while(!q.empty())
    {
        cout<< q.top() << ' ';
        q.pop();
    }
    return 0;
}