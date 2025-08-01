#include<stdio.h>
void main()
{
    int i=0;
    char s[30];
    printf("\nEnter your name: ");
    gets(s);
    int length = strlen(s);
    printf("\nYour name by single charecter = \n");
    while(s[i]!='\0')
    {
        printf("%c\n",s[i]);
        i++;
    }
    printf("\nThe length of your name is with built in function = %d",length);
    printf("\nThe length of your name is using while loop = %d",i);
    return 0;
}
