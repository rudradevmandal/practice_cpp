#include <iostream>
using namespace std;

const int MAX = 100;
int F[MAX];

int Factorial(int x)
{
    if (x < 0)
    {
        cout << "Error: Cannot find factorial of negative numbers." << endl;
        return 0;
    }
    if (x == 0 or x == 1)
        return 1;
    else if (F[x] != 0)
        return F[x];
    F[x] = x * Factorial(x - 1);
    return F[x];
}

int Fibonacci(int n)
{
    if (n < 0)
    {
        cout << "Error: Wrong position entered. Position should be greater than or equal to 0." << endl;
        return 0;
    }
    if (n == 1)
        return 0;
    if (n == 2 or n == 3)
        return 1;
    if (F[n] != 0)
        return F[n];
    F[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    return F[n];
}

int Exponent(int x, int n)
{
    if (n == 1)
        return x;
    if (n % 2 == 0)
    {
        int result = Exponent(x, n / 2);
        return result * result;
    }
    return x * Exponent(x, n - 1);
}
int main()
{
    int x = 2;
    int n = 5;
    // cout << "Factorial of " << x << " is " << Factorial(x) << endl;
    // cout << "Fibonacci at " << x << " is " << Fibonacci(x) << endl;
    cout << x << " to the power of " << n << " is " << Exponent(x, n) << endl;
}