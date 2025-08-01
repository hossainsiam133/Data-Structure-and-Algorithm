#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Totall Elements: ";
    cin>>n;
    int arr[n];
    int item;
    cout<<"Enter the values of the Array :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ///Main mechanism of Insertion Sort
    for(int i=1;i<n;i++)
    {
      item=arr[i];
      int j=i-1;
      while(j>=0 && arr[j]>item)
      {
        arr[j+1]=arr[j];
        j=j-1;
      }
      arr[j+1]=item;
    }
    cout<<"After Insertion Sort: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}