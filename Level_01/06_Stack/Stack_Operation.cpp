#include<iostream>
#define STACK_MAX 100

using namespace std;
typedef struct
{
    int top;
    int data[STACK_MAX];
} stack;
void push(stack *p, int item)
{
    if(p->top < STACK_MAX)
    {
       p->data[p->top] = item;
       cout<< "Pushed item is: "<< item << endl;
       p->top++;
    }
    else
    {
        cout<< "Stack is Full"<< endl;
    }
}
int pop(stack *p)
{
    int item;
    if(p->top == 0)
    {
        cout<< "Stack is Empty"<< endl;
        return -1;
    }
    else
    {
        p->top--;
        item = p->data[p->top];
        return item;
    }
}
int main()
{
    stack book;
    int item;
    book.top = 0;
    //Pushing the values and sent the address of the object of the stack
    push(&book, 1);
    push(&book, 2);
    push(&book, 3);
    //Poping the values from the stack with the address as the arguaments of pointer type pop function parameter
    cout<< endl;
    item = pop(&book);
    cout<< "Poped item is: "<< item << endl;

    item = pop(&book);
    cout<< "Poped item is: "<< item << endl;
   
    item = pop(&book);
    cout<< "Poped item is: "<< item << endl;
    return 0;
}
