///Delating
#include<stdio.h>
int main()
{
    int a[30],i,n,k,item;
    printf("\aHow many elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the position where you wish to DELETE: ");
    scanf("%d",&k);
    printf("\n\aEnter the Item: ");
    scanf("%d",&item);
    if(k>=n+1)
    {
        printf("\a\nDeletation is not possible");
    }
    else
    {
        for(i=k-1;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;
    printf("\nFinal Array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    }
}
