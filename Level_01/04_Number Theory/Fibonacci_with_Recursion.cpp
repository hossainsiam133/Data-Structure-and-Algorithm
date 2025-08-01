#include <iostream>
using namespace std;

int fibo(int a)
{
    if (a == 0)
        return 0;
    else if (a == 1)
        return 1;
    else
    {
        int sum = fibo(a - 1) + fibo(a - 2);
        return sum;
    }
};

int main()
{
    int n;
    cout<< "Enter the Range: ";
    cin >> n;
    cout<< "Fibonacci Series with the Range of " << n << " is: ";
    for (int i = 0; i < n; i++)
    {
        cout << fibo(i) << " ";
    }
    return 0;
}