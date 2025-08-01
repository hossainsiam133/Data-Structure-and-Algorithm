#include<stdio.h>
void main()
{
    int row,col,n;
    printf("Enter the last Alphabet to print: ");
    scanf("%d",&n);
    for(row=1;row<=n;row++)
    {
        for(col=n;col>row;col--)
        {
            printf("%d ",col);  //for Capital letters ASCII Stars from 64 & Small letters 96.
        }
        printf("\n");
    }

    /*for(row=n-1;row>=1;row--)
    {
        for(col=1;col<=row;col++)
        {
            printf("%d ",col);  //for Capital letters ASCII Stars from 64 & Small letters 96.
        }
        printf("\n");
    }*/

}
