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

bool isBalances(char top, char ch)
{
    if (top == '(' && ch == ')' || top == '{' && ch == '}' || top == '[' && ch == ']')
        return 1;
    else
        return 0;
}
int main()
{
    Fast;
    string s; // [{()}]
    cin >> s;
    bool ans = true;
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else
        {
            if (st.empty())
            {
                ans = false;
                break;
            }
            else
            {
                if (isBalances(st.top(), ch))
                    st.pop();
                else
                {
                    ans = false;
                    break;
                }
            }
        }
    }
    if (ans)
        Yes;
    else
        No;
    return 0;
}