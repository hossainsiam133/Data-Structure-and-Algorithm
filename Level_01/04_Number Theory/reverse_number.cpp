#include<iostream>
using namespace std;
int main()
{
    long long int n,rev,last_digit;
    cin>>n;
    rev=0;
    while(n>0)
    {
        last_digit=n%10;
        rev=rev+last_digit;
        n=n/10;
    }
    cout<<rev;
    return 0;
}

