#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline char(10)
#define Fast		\
ios_base::sync_with_stdio(false);		\
cin.tie(0);		\
cout.tie(0);
#define Yes cout<<"YES\n"
#define No cout<<"NO\n"
#define print(v) for(auto &it : v){cout<< it<<' '; } cout<<endl;

int main()
{
    Fast;
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> q;
    q.push({1,-2});
    q.push({1,-0});
    q.push({3,-5});
    q.push({3,-2});
    q.push({5,-5});

    while(!q.empty())
    {
        cout<< q.top().first << ' ' << q.top().second*-1 << nline;
        q.pop();
    }
    return 0;
}