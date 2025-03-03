#include <iostream>
using namespace std;

int FindNumberOfRotations(int *A, int n)
{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    int x = A[mid];
    int index = mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        // cout << "x=" << x << ", index=" << index << endl;
        // cout << "low=" << low << ", mid=" << mid << ", high=" << high << endl;
        // cout << "A[low]=" << A[low] << ", A[mid]=" << A[mid] << ", A[high]=" << A[high] << endl;
        if (A[mid] < x)
        {
            x = A[mid];
            index = mid;
        }
        if (high == low)
            return index;
        if (A[low] - A[mid] >= A[mid] - A[high])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return index;
}

int FindRotations(int *A, int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        if (A[low] <= A[high]) // Array is sorted
            return low;

        int mid = (low + high) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        // Pivot position - THis should be the lowest as in this position, both the side numbers are greater.
        // {8 9 10 1(P) 2 3 4} - 1 is the only number which has greater value 10 and 2 on both sides.
        // Every other number has one side lesser than the other.
        if (A[prev] >= A[mid] && A[next] >= A[mid])
            return mid;
        else if (A[mid] >= A[low]) // If lowest index is less than mid, then the array is sorted till mid position. Need to search on the right side.
            low = mid + 1;
        else if (A[mid] <= A[high]) // If highest index is greater than mid, then the array is sorted from mid position till highest position. Need to search on the left side.
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int x;
    // int A[10] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    // int A[10] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    // int A[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    // int A[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    int A[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Array is rotated " << FindNumberOfRotations(A, size) << " times." << endl;
    cout << "Array is rotated " << FindRotations(A, size) << " times." << endl;
}