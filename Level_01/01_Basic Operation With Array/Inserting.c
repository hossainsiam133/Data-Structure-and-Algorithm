///Inserting
#include<stdio.h>
int main()
{
    int a[50],n,k,item,i;
    printf("How many elements: ");
    scanf("%d",&n);
    printf("\nEnter the values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nEnter the position: ");
    scanf("%d",&k);
    printf("\nEnter the value: ");
    scanf("%d",&item);
    for(i=n-1;i>=k-1;i--)
    {
        a[i+1]=a[i];
    }
    a[k-1]=item;
    n++;
    printf("\nThe Final Array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
