#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    else
    return gcd(b,a%b);
}
int gcd_mult(int arr[],int n)
{
    int result = arr[0];
    for(int i=1;i<n;i++)
    {
        result = gcd(result,arr[i]);
        if(result == 1)
        {
            break;
        }
    }
    return result;
}
int main() 
{
 
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int final_gcd = gcd_mult(arr,n);
    cout<<final_gcd<<endl;
    return 0;
}
