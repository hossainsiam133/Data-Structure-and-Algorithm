#include <iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()
{
    int a,b;
    int x, y;
    cin>>a>>b;
    int result = gcd(a, b, x, y);

    cout << "GCD of " << a << " and " << b << " is: " << result << endl;
    cout << "Coefficients x and y are: " << x << ", " << y << endl;

    return 0;
}
