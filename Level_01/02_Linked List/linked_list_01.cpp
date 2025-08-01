#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data<<endl;
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    /// Memory alloacte in the heap...
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    // Link 1st and 2nd Nodes
    head->data = 7;
    head->next = second;
    // Link 2nd and 3rd Nodes
    second->data = 8;
    second->next = third;
    // 3rd and 4th
    third->data = 9;
    third->next = fourth;
    //Terminal Nodes
    fourth->data=66;
    fourth->next=NULL;
    traversal(head);
}