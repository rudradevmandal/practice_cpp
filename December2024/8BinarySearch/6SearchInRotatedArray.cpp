#include <iostream>
using namespace std;

int FindNumber(int *A, int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
            return ++mid;
        // If array is sorted till id and x is between A[low] and A[mid]. Search in the left else search right.
        else if (A[low] <= A[mid])
        {
            if (x >= A[low] && x <= A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // If array is sorted after mid and x is between A[mid] and A[high]. Search in the right else search left.
        else if (A[high] >= A[mid])
        {
            if (x >= A[mid] && x <= A[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int x;
    int A[10] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    // int A[10] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    // int A[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    // int A[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;
    cout << x << " is at " << FindNumber(A, size, x) << " position." << endl;
}
