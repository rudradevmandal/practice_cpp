#include <iostream>
using namespace std;

// Modular Exponentiation x^n % M
// 5^2 % 7 = 4
// 5^3 % 7 = 6

int FindExponentModular(int x, int n, int m)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) // even
    {
        int y = FindExponentModular(x, n / 2, m);
        return (y * y) % m;
    }
    else
    {
        return ((x % m) * FindExponentModular(x, n - 1, m)) % m;
    }
}

int main()
{
    int x, n, m;
    cout << "Enter a base number to calculate exponent: ";
    cin >> x;
    cout << "Enter the exponent: ";
    cin >> n;
    cout << "Enter the Modular number: ";
    cin >> m;
    cout << x << "to the power " << n << " modular " << m << "is " << FindExponentModular(x, n, m) << endl;
}