///Traversing
#include<stdio.h>
int main()
{
    int mark[5]= {80,60,70,85,75};
    int sum=0,i;
    for( i=0; i<5; i++)
    {
        printf("Mark[%d]=%d\n",i+1,mark[i]);
        sum=sum+mark[i];
    }

    printf("\nSum=%d%d",sum,i);
    return 0;
}
