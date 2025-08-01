#include<iostream>
#include<stdlib.h>
using namespace std;
struct stack
{
   int size;
   int top;
   int *arr; /* data */
};
int isEmpty(struct stack *ptr)
{
     if(ptr->top == -1)
     {
        return 1;
     }
     else
     {
        return 0;
     }
};
int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    struct stack *s;
    cout<<"Size: ";
    cin>>s->size;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    //Pushing Manually
    for(int i=0;i<s->size;i++)
    {
        cin>>s->arr[i];
        s->top++;
    }

    if(isEmpty(s))
    {
        cout<<"The stack is Empty"<<endl;
    }
    else
    cout<<"Stack is not Empty"<<endl;
    if(isFull(s))
    {
        cout<<"Stack is FUll"<<endl;
    }
    else
    cout<<"Stack is not Full"<<endl;

}
