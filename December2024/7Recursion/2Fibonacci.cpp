#include <iostream>
using namespace std;

// Long time - Time Complexity is O(2^1.614)
int Fibonacci(int n)
{
    if (n <= 1)
        return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int F[100];
// Long time - Time Complexity is O(n)
int FibonacciMemoization(int n)
{
    if (n <= 1)
        return n;
    if (F[n] != 0)
        return F[n];
    else
        F[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    return F[n];
}

// Iterative - O(n)
int FibItr(int n)
{
    if (n <= 1)
        return n;
    int result;
    for (int i = 0; i < n; i++)
    {
        result += i;
    }
    return result;
}

int main()
{
    int x;
    cout << "Enter a index till which Fibonacchi series is calculated: ";
    cin >> x;
    cout << "Fibonacci series (Iterative) till " << x << " is " << Fibonacci(x) << endl;
    cout << "Fibonacci series (Memoization) till " << x << " is " << Fibonacci(x) << endl;
    cout << "Fibonacci series till " << x << " is " << Fibonacci(x) << endl;
}