#include<stdio.h>
int main()
{

    char str1[50]="My name is ";
    char str2[]="Evrahim Hossain Siam.";
    int i=0;
    while(str1[i]!='\0')
    {
        i++;
    }
    int z=0;
    while(str2[z]!='\0')
    {
        str1[i+z]=str2[z];
        z++;
    }
    printf("Final string cat is= %s",str1);
    return 0;

}
