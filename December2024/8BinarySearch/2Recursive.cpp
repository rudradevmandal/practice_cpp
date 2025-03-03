#include <iostream>
using namespace std;

int BinarySearchRecursive(int *A, int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (A[mid] == x)
        return mid + 1;
    else if (x < A[mid])
        return BinarySearchRecursive(A, low, mid - 1, x);
    else
        return BinarySearchRecursive(A, mid + 1, high, x);
}

int main()
{
    int x;
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;
    cout << x << " is at " << BinarySearchRecursive(A, 0, size - 1, x) << endl;
}