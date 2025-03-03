#include <iostream>
using namespace std;

void PrintArray(int *A, int low = 0, int size = 10)
{
    for (int i = low; i <= size; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;
}

void Swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int Partition(int *A, int low, int high)
{
    int pivot = A[high];
    int partitionIndex = low;

    for (int i = low; i < high; i++)
    {
        if (A[i] <= pivot) // Keep all elements lesser than pivot to the left of partitionIndex
        {
            Swap(A + i, A + partitionIndex);
            partitionIndex++;
        }
    }
    Swap(A + high, A + partitionIndex); // Swap pivot with the partition index
    return partitionIndex;
}

// Recursive function to sort an array of integers.
void QuickSort(int *A, int low, int high)
{

    if (low < high)
    {
        int pivotIndex = Partition(A, low, high);
        QuickSort(A, low, pivotIndex - 1);
        QuickSort(A, pivotIndex + 1, high);
    }
    // int pivotIndex = (low + high) / 2;
    // int pivot = A[pivotIndex];

    // int count = 0;

    // // Find the number of elements less than pivot
    // for (int i = low; i <= high; i++)
    //     if (A[i] < pivot)
    //         count++;

    // if ((low + count) != pivotIndex) // Swap the pivot to the right place
    //     Swap(A + low + count, A + pivotIndex);

    // pivotIndex = low + count; // Modify pivotIndex to the new index

    // int l = low;
    // int h = high;

    // // Since pivot is at right place, use 2 index low and high
    // // Swap low and high when left is greater than pivot and right is lessor than pivot
    // while (pivotIndex > low and pivotIndex < high and l < h)
    // {
    //     // Swap only when left is greater and right is smaller
    //     if (A[l] >= pivot and A[h] < pivot)
    //     {
    //         Swap(A + l, A + h);
    //         l++;
    //         h--;
    //     }
    //     if (A[l] < pivot)
    //         l++;
    //     if (A[h] > pivot)
    //         h--;
    // }

    // if (pivotIndex > low) // If pivot is at lowes index, minumum number of that sub-array is found. No need to call left sub-array
    // if (pivotIndex < high) // If pivot is at highest index, maximum number of that sub-array is found. No need to call right sub-array
}

int main()
{
    int A[10] = {7, 5, 4, 2, 6, 9, 1, 3, 10, 8};
    int size = sizeof(A) / sizeof(int);
    cout << "Original array is ";
    PrintArray(A, 0, size - 1);

    QuickSort(A, 0, size - 1);
    cout << "Sorted array using Quick sort is ";
    PrintArray(A, 0, size - 1);
}