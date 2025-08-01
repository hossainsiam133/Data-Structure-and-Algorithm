#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0){
        return false;
        }
    }
    return true;

}
int main()
{
    int a,b,i;
    cin>>a>>b;
    for(i=a;i<=b;i++)
    {
        if(prime(i))
        {
            cout<<i<<endl;
        }
    }
    return 0;
}

