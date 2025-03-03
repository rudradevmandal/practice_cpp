#include <iostream>
using namespace std;

void PrintArray(int A[10])
{
    cout << "Start-->";
    for (int i = 0; i < 10; i++)
        cout << "[" << A[i] << "]-->";
    cout << "End" << endl;
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void SelectionSort(int *A)
{
    for (int i = 0; i < 10; i++)
    {
        int *min = A + i;
        for (int j = i + 1; j < 10; j++)
        {
            if (A[j] < *min)
                min = A + j;
        }
        Swap(A + i, min);
    }
}

void BubbleSort(int *A)
{
    for (int i = 0; i < 10; i++)
    {
        bool swap = false;
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap = true;
                Swap(A + j, A + j + 1);
            }
        }
        if (!swap) // No swap means array is already sorted
            break;
    }
}

void InsertionSort(int *A)
{
    int count = 0;
    for (int i = 1; i < 10; i++)
    {
        int j = i;
        while (j > 0 and A[j - 1] > A[j])
        {
            Swap(A + j - 1, A + j);
            j--;
            count++;
        }
    }
    cout << "count=" << count << endl;
}

void MergeArrays(int *R, int *A, int m, int *B, int n)
{
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < m and j < n)
    {
        if (A[i] < B[j])
        {
            R[count++] = A[i++];
        }
        else
        {
            R[count++] = B[j++];
        }
    }
    while (i < m)
        R[count++] = A[i++];
    while (j < n)
        R[count++] = B[j++];
}

void MergeSort(int *A, int size)
{
    if (size < 2)
        return;

    int mid = size / 2;
    int *leftArray = new int[mid];
    int *rightArray = new int[size - mid];

    for (int i = 0; i < mid; i++)
        leftArray[i] = A[i];
    for (int i = 0; i < size - mid; i++)
        rightArray[i] = A[mid + i];

    MergeSort(leftArray, mid);
    MergeSort(rightArray, size - mid);
    MergeArrays(A, leftArray, mid, rightArray, size - mid);

    delete[] leftArray;
    delete[] rightArray;
}

int GetPartitionIndex(int *A, int low, int high)
{
    int partitionIndex = high;
    for (int i = 0; i <= high; i++)
    {
        if ((i < partitionIndex and A[i] > A[partitionIndex]) or (i > partitionIndex and A[i] < A[partitionIndex]))
        {
            Swap(A + i, A + partitionIndex);
            partitionIndex = i;
        }
    }
    return partitionIndex;
}

void QuickSort(int *A, int low, int high)
{
    if (low > high)
        return;
    int partitionIndex = GetPartitionIndex(A, low, high);
    QuickSort(A, 0, partitionIndex - 1);
    QuickSort(A, partitionIndex + 1, high);
}

int main()
{
    int A[10] = {7, 5, 4, 2, 6, 9, 1, 3, 10, 8};
    cout << "Original array is " << endl;
    PrintArray(A);

    InsertionSort(A);
    // QuickSort(A, 0, 9);
    cout << "Sorted array using QuickSort is " << endl;
    PrintArray(A);
}