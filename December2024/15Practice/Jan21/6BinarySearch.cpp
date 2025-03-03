#include <iostream>
using namespace std;

int BinarySearch(int *A, int n, int x)
{
    if (n == 0)
    {
        cout << "Error: Given array is empty." << endl;
        return -1;
    }
    int high = n - 1;
    int low = 0;
    int mid = (high + low) / 2;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (x < A[mid])
            high = mid - 1;
        else if (x > A[mid])
            low = mid + 1;
        else
            return mid + 1;
    }
    return -1;
}

int BinarySearchRecursive(int *A, int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (x < A[mid])
        return BinarySearchRecursive(A, low, mid - 1, x);
    else if (x > A[mid])
        return BinarySearchRecursive(A, mid + 1, high, x);
    else
        return mid + 1;
}

int FindFirstOrLastOccurrence(int *A, int size, int x, bool isFirst)
{
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    int result = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < A[mid])
            high = mid - 1;
        else if (x > A[mid])
            low = mid + 1;
        else
        {
            result = mid + 1;
            if (isFirst)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return result;
}

int CountOccurrence(int *A, int size, int x)
{
    int first = FindFirstOrLastOccurrence(A, size, x, true);
    int last = FindFirstOrLastOccurrence(A, size, x, false);
    if (first == -1 && last == -1)
        return 0;
    return last - first + 1;
}

int CountRotations(int *A, int low, int high)
{
    if (A[low] < A[high])
        return low;
    int mid = (low + high) / 2;
    if (A[mid - 1] > A[mid] and A[mid + 1] > A[mid])
        return mid;
    else if (A[low] < A[mid])
        return CountRotations(A, mid + 1, high);
    else
        return CountRotations(A, low, mid - 1);
}

int SearchInRotatedArray(int *A, int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (x < A[mid])
    {
        if (x >= A[low])
            return SearchInRotatedArray(A, low, mid - 1, x);
        else
            return SearchInRotatedArray(A, mid + 1, high, x);
    }
    else if (x > A[mid])
    {
        if (x <= A[high])
            return SearchInRotatedArray(A, mid + 1, high, x);
        else
            return SearchInRotatedArray(A, low, mid - 1, x);
    }
    else
        return mid + 1;
}

int main()
{
    int x = 5;
    // int A[15] = {1, 2, 3, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    // int A[10] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    // int A[10] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    int A[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    // int A[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    // int A[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    // int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(A) / sizeof(int);
    // cout << "Size= " << size << endl;
    // cout << "Enter a number to search: ";
    // cin >> x;
    cout << x << " is at " << BinarySearch(A, size, x) << endl;
    cout << x << " is at " << BinarySearchRecursive(A, 0, size - 1, x) << endl;
    cout << x << " occurs first at " << FindFirstOrLastOccurrence(A, size, x, true) << " and last occurs at " << FindFirstOrLastOccurrence(A, size, x, false) << endl;
    cout << x << " occurs " << CountOccurrence(A, size, x) << " times." << endl;
    cout << "Array is rotated " << CountRotations(A, 0, size - 1) << " times." << endl;
    cout << x << " is at " << SearchInRotatedArray(A, 0, size - 1, x) << endl;
}