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
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(3);
    dq.push_front(2);
    dq.push_front(4);
    print(dq);
    dq.pop_front();
    dq.pop_back();
    cout << dq.size() << ' ' << dq.front() << ' ' << dq.back() << nline;
    print(dq);
    return 0;
}