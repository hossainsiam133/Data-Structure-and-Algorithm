///Searching
#include<iostream>
using namespace std;
int main()
{
    int n,item,i,loc=0;
    cout<<"How many elements: ";
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Item that you want to search: ";
    cin>>item;
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            loc=i+1;
            break;
        }
    }
    if(loc==0)
        cout<<"Item is not found!";
    else if(loc>0)
        cout<<item<<" Location is: "<<loc;
}


