#include <iostream>
using namespace std;

void PrintArray(int A[10])
{
    for (int i = 0; i < 10; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;
}

int FindIndexBinarySearch(int *A, int size, int n)
{
    int low = 0;
    int high = size;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (n < A[mid])
            high = mid - 1;
        else if (n > A[mid])
            low = mid + 1;

        if (low == high)
            break;
    }
    return low;
}

void InsertionSort(int (&A)[10])
{
    int size = sizeof(A) / sizeof(int);
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        // cout << "FindIndexBinarySearch size=" << i << endl;
        int indexToInsert = i;
        int numToInsert = A[i];
        while (indexToInsert > 0 and A[indexToInsert - 1] > numToInsert)
        {
            A[indexToInsert] = A[indexToInsert - 1];
            indexToInsert--;
            count++;
        }
        A[indexToInsert] = numToInsert;
        // if (indexToInsert != i) // If new index is same as the current index. The number is already at the correct place in the array
        // {
        //     // Shift all elements from indexToInsert to i and insert A[i] at A[indexToInsert]
        //     for (int j = i; j > indexToInsert; j--)
        //     {
        //         A[j] = A[j - 1];
        //     }
        //     A[indexToInsert] = numToInsert;
        // }
        cout << "count=" << count << endl;
        PrintArray(A);
    }
}

int main()
{
    int A[10] = {7, 5, 4, 2, 6, 9, 1, 3, 10, 8};
    cout << "Original array is ";
    PrintArray(A);

    InsertionSort(A);
    cout << "Sorted array using Insertion sort is ";
    PrintArray(A);
}