//1^2*2^2*3^2*.....n^2=?
#include<stdio.h>
void main()
{
    ///int i;
    double num,sum,i;
    printf("Enter the last numbers of the series:");
    scanf("%lf",&num);
    double mult=1;

    for(i=1; i<=num; i++)
    {
        if(i==1)
            printf("\n%.2lf^2* ",i);
        else if(i==num)
            printf("%.2lf^2= ",i);
        else
            printf("%.2lf^2* ",i);
        mult=mult*i*i;
    }
    printf("%.2lf",mult);

}

