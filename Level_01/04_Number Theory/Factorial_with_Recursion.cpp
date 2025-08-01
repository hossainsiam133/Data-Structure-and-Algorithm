#include <iostream>
using namespace std;

int factorial(int a)
{
    int f;
    if (a == 0 || a == 1) return 1;
    f = a * factorial(a - 1);
    return f;
};

int main()
{
    int n;
    cout<< "Enter any integer number between 0-31: ";
    cin >> n;
    int fact = factorial(n);
    cout << "Factorial of " << n << " is: " << fact << endl;
    return 0;
}
