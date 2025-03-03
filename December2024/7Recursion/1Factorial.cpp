#include <iostream>
using namespace std;

int Factorial(int n)
{
    if (n == 0)
        return 1;
    return n * Factorial(n - 1);
}

int main()
{
    int x;
    cout << "Enter a number to calculate factorial: ";
    cin >> x;
    cout << "Factorial of " << x << " is " << Factorial(x) << endl;
}