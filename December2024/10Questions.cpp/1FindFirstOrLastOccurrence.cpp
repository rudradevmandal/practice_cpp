#include <iostream>
using namespace std;

int FindFirstOrLastOccurence(int *A, int low, int high, int x, bool isFirst)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    int result = -1;

    if (x < A[mid]) // Find x in left
        return FindFirstOrLastOccurence(A, low, mid - 1, x, isFirst);
    else if (x > A[mid]) // Find x in right
        return FindFirstOrLastOccurence(A, mid + 1, high, x, isFirst);
    else
    {
        result = mid + 1;
        if (isFirst and ((result = FindFirstOrLastOccurence(A, low, mid - 1, x, isFirst)) == -1)) // If x==A[mid] - Go left to find the first occurence
            result = mid + 1;
        else if ((result = FindFirstOrLastOccurence(A, mid + 1, high, x, isFirst)) == -1) // If x==A[mid] - Go left to find the last occurence
            result = mid + 1;
    }
    return result; // Incrementing 0th position to 1st place and so on.
}

int main()
{
    int x;
    int A[10] = {1, 2, 3, 3, 5, 5, 5, 8, 10, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;
    cout << x << " occurs first at " << FindFirstOrLastOccurence(A, 0, size - 1, x, true) << " and last at " << FindFirstOrLastOccurence(A, 0, size - 1, x, false) << endl;
}