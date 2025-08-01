///Write something ex:Siam161 I will tell you that how many numbers,Capital and Small Letters.
#include<stdio.h>
int main()
{
    int i,capital,small,digit,ch;
    char str[100];
    printf("Enter something:");
    gets(str);
    i=capital=small=digit=0;
    while(str[i]!='\0')
    {
        if(str[i]>='A'&&str[i]<='Z')

            capital++;

        else if(str[i]>='a'&&str[i]<='z')

            small++;

        else if(str[i]>='0'&&str[i]<='9')

            digit++;

        i++;
    }

    printf("\nNumber of capital letters:%d",capital);
    printf("\nNumber of small letters:%d",small);
    printf("\nNumber of digit:%d",digit);

    return 0;

}

