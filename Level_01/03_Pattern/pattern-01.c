#include<stdio.h>
void main()
{
    char row,col,n;
    printf("Enter the Row numbers that you want to see :");
    scanf("%d",&n);

    for(row=1; row<=n; row++)
    {
        for(col=1; col<=row; col++)
        {
            if(row%2==0)
            {
                printf("0 ");
                continue;

            }
            else if(row%2!=0)
            {
                printf("1 ");
                continue;
            }
            ///printf("%d ",col);
        }
        printf("\n");
    }

}
