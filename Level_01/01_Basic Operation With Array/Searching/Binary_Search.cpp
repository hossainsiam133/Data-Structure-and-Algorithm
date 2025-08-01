#include <iostream>
 
using namespace std;
 
int main() 
{
    int n;
    cout<<"Size of Array :";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //Using Bubble Sort...
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    //Priint after 
    cout<<"After Sorting :";
     for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int k;
    cout<<"Your Search Item is :";
    cin>>k;
    int s=0,e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==k)
        {
            cout<<a[mid]<<" Is found in "<<mid+1<<" Position"<<endl;
            break;
        }
        else if(a[mid]>k)
        {
           e=mid-1;
        }
        else 
        {
            s=mid+1;
        }
    }
    return 0;
}