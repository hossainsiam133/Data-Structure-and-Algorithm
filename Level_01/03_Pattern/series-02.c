//1-2+3-4+5-........n
#include<stdio.h>
void main()
{
    int i,num,sum_even=0,sum_odd=0;

    printf("Enter the last digit: ");
    scanf("%d",&num);
    for(i=1; i<=num; i++)
    {
        if(i%2==0)
            sum_even=sum_even-i;
        else if(i%2!=0)
            sum_odd=sum_odd+i;
    }
    int total_sum=sum_even+sum_odd;
    printf("\nTotal sum is:%d",total_sum);


}
