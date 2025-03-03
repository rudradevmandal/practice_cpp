#include <iostream>
using namespace std;

void PrintArray(int *A, int size = 10)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;
}

// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A, int *leftArray, int leftSize, int *rightArray, int rightSize)
{

    int i = 0; // i - to mark the index of left sub-array (leftArray)
    int j = 0; // j - to mark the index of right sub-array (rightArray)
    int k = 0; // k - to mark the index of merged main-array (A)

    while (i < leftSize and j < rightSize)
    {
        if (leftArray[i] < rightArray[j])
        {
            A[k++] = leftArray[i++];
        }
        else
        {
            A[k++] = rightArray[j++];
        }
    }
    // If left sub-array (leftArray) has elements remaining
    while (i < leftSize)
    {
        A[k++] = leftArray[i++];
    }
    // If right sub-array (rightArray) has elements remaining
    while (j < rightSize)
    {
        A[k++] = rightArray[j++];
    }
}

// Recursive function to sort an array of integers.
void MergeSortRecursive(int *A, int size)
{
    int *LeftArray, *RightArray;

    if (size < 2) // base condition. If the array has less than two element, do nothing.
        return;

    int mid = size / 2; // find the mid index.

    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    LeftArray = new int[mid];
    RightArray = new int[size - mid];

    for (int i = 0; i < mid; i++) // creating left subarray
        LeftArray[i] = A[i];

    for (int i = mid; i < size; i++) // creating right subarray
        RightArray[i - mid] = A[i];

    MergeSortRecursive(LeftArray, mid);
    MergeSortRecursive(RightArray, size - mid);
    Merge(A, LeftArray, mid, RightArray, size - mid);
    delete LeftArray;
    delete RightArray;
}

int main()
{
    int A[10] = {7, 5, 4, 2, 6, 9, 1, 3, 10, 8};
    cout << "Original array is ";
    PrintArray(A);

    int size = sizeof(A) / sizeof(int);
    MergeSortRecursive(A, size);
    cout << "Sorted array using Merge sort is ";
    PrintArray(A);
}