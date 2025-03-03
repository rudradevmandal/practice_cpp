#include <iostream>
using namespace std;

int FindExponent(int x, int n)
{
    if (n == 1)
        return x;
    else if (n % 2 == 0)
    {
        int y = FindExponent(x, n / 2);
        return y * y;
    }
    else
        return x * FindExponent(x, n - 1);
}

int main()
{
    int x, n;
    cout << "Enter a base number to calculate exponent: ";
    cin >> x;
    cout << "Enter the exponent: ";
    cin >> n;
    cout << x << "to the power " << n << " is " << FindExponent(x, n) << endl;
}