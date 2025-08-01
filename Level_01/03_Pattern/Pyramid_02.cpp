#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n;
    cout<<"Enter the Row: ";
    cin>>n;
    for(i=n;i>0;i--)
    {
         for(k=i;k<n;k++)
            {
                cout<<" ";
            }

        for(j=0;j<i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}

