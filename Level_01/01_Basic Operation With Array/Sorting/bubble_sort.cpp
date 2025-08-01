#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the total elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the Array Values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    while (count < n - 1)
    {
        for (int i = 0; i < n - count - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i + 1];
                a[i + 1] = a[i];
                a[i] = temp;
            }
        }
        count++;
    }
    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}