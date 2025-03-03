#include <iostream>
using namespace std;

int BinarySearch(int *A, int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
            return mid + 1;
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int x;
    int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;
    cout << x << " is at " << BinarySearch(A, size, x) << endl;
}