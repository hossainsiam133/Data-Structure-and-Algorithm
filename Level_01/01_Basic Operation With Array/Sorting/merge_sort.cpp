#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid, int r)
{
    int n1= mid-l+1;
    int n2= r-mid;

    int a[n1];
    int b[n2]; //Temp Arrays

    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    } 
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;i++;
        }
        else
        {
            arr[k]=b[j];
            k++;j++;
        }

    } 
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);

        merge(arr,l,mid,r);

    }
}
//Binary Search...
int bin_srch(int a[],int n,int k)
{
    int s=0;
    int e=n;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==k)
        {
            return mid;
        } 
        else if(a[mid]>k)
        {
            e=mid-1;
        }
        else if(a[mid]<k)
        {
            s=mid+1;
        }
    }
    return -1;
}
int main() 
{
    int arr[]={5,3,4,2,1};
    mergesort(arr,0,4);
    for(int i=0;i<5;i++)
    {
       cout<<arr[i]<<" "; 
    }
     cout<<endl;
    //Binary Srearch...
    int k;
    int n=sizeof(arr)/4;
    cout<<"Search Item is: ";
    cin>>k;
     int index=bin_srch(arr,n,k);
    if(index==-1)
        cout<<"Items is not found!";
    else
        cout<<arr[index]<<" Found in the position: "<<index+1;

    ///Total complexity of this code is O(n log n)
    return 0;
}
