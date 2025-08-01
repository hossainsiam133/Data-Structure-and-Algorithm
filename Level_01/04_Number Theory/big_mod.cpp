#include <iostream>
using namespace std;
long long int big_mod(long long int a,long long int b,long long int m)
{
    if(b==0) return 1;
    if(b%2==1)
    {
       long long int x,y;
       x = a%m;
       y = big_mod(a,b-1,m);
       return (x*y)%m;
    }
    else if(b%2==0)
    {
        long long int result;
        result = big_mod(a,b/2,m);
        return (result * result) % m;
    }
}
int main()
{
    long long int a, b, m;
    cout<<"Input as a^b mod m: ";
    //Think as 2^5 mod 7...
    while(cin>>a>>b>>m)
    {
        cout<<big_mod(a,b,m)<<endl;
    }
    return 0;
}