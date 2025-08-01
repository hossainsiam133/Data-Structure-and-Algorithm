#include <iostream>
using namespace std;
void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void generatePermutations(char elements[], int start, int end)
{
    if (start == end)
    {
        for (int i = 0; i <= end; i++)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        for (int i = start; i <= end; i++)
        {
            swap(elements[start], elements[i]);
            generatePermutations(elements, start + 1, end);
            swap(elements[start], elements[i]); // Backtrack
        }
    }
}

int main()
{
    int n;
    cout<<"Size of Word : ";
    cin>>n;
    char elements[n];
    for(int i=0;i<n;i++)
    {
      cin>>elements[i];
    }
    generatePermutations(elements, 0, n - 1);

    return 0;
}
