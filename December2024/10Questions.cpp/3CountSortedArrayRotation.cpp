#include <iostream>
using namespace std;

// In a rotated sorted array, pick any element. One side should be sorted
// Discard the sorted side and continue with the other side
int FindNumberOfRotationsRecursion(int *A, int low, int high)
{
    if (A[low] <= A[high])
        return low;
    int mid = (low + high) / 2;
    int result = 0;
    if (A[mid] > A[high])
    {
        result = FindNumberOfRotationsRecursion(A, mid + 1, high);
        result = result == 0 ? mid : result;
    }
    else if (A[mid] < A[low])
    {
        result = FindNumberOfRotationsRecursion(A, low, mid - 1);
        result = result == 0 ? mid : result;
    }
    else
        result = FindNumberOfRotationsRecursion(A, low, mid - 1);
    return result;
}

int FindNumberOfRotationsIterative(int *A, int size)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int prev = (size + mid - 1) % size;

        if (A[prev] >= A[mid]) // Previous index is greater than current.
            return mid;
        else if (A[low] > A[mid]) // lowest index is greater than current. Lower half is not sorted. Go left.
            high = mid - 1;
        else if (A[high] < A[mid]) // Higher index is less than current. Higher half is not sorted. Go right.
            low = mid + 1;
        else // sorted
            return low;
    }
    return 0;
}

int main()
{
    int x;
    // int A[10] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    // int A[10] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    // int A[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int A[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    // int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Array is rotated " << FindNumberOfRotationsRecursion(A, 0, size - 1) << " times." << endl;
    cout << "Array is rotated " << FindNumberOfRotationsIterative(A, size) << " times." << endl;
}