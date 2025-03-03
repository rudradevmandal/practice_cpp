#include <iostream>
using namespace std;

int FindFirstOccurence(int *A, int n, int x)
{
    int first = -2;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ++first;
}

int FindLastOccurence(int *A, int n, int x)
{
    int first = -2;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
        {
            first = mid;
            low = mid + 1;
        }
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ++first;
}

int main()
{
    int x;
    int A[10] = {4, 4, 4, 4, 4, 4, 4, 8, 9, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;
    cout << x << " first occurs at " << FindFirstOccurence(A, size, x) << endl;
    cout << x << " last occurs at " << FindLastOccurence(A, size, x) << endl;
}