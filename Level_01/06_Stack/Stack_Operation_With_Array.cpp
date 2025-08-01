#include <iostream>
#define SIZE 3
using namespace std;
int top = -1;
int inp_array[SIZE];

void push()
{
	int x, i;
	if (top == SIZE - 1)
	{
		cout << "Present situatation-(Push) of the Stack is: Overflow" << endl;
	}
	else
	{
		cout << "Enter your Elements: ";
		cin >> x;
		top++;
		inp_array[top] = x;
		cout << "Present situatation-(Push) of the stack: ";
		for (i = 0; i <= top; i++)
		{
			cout << inp_array[i] << " ";
		}
		cout << endl;
	}
}
void pop()
{
	int item;
	if (top <= 0)
	{
		cout << "Present situatation-(Pop) of the Stack is: Empty" << endl;
		top = -1;
	}
	else
	{
		top--;
		cout << "Present situatation-(Pop) of the stack: ";
		for (int i = 0; i <= top; i++)
		{
			cout << inp_array[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int choice;
	while (choice != 0)
	{
		cout << "Perform operation on the stack: " << endl;
		cout << "1.Push" << endl
			 << "2.Pop" << endl
			 << "0.End" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			push();
			break;
		}
		case 2:
		{
			pop();
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "Invalid Choice" << endl;
		}
		}
	}
	return 0;
}
