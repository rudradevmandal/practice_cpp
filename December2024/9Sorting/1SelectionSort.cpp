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

void SelectionSort(int (&A)[10])
{
    int size = sizeof(A) / sizeof(int);

    for (int i = 0; i < size - 1; i++)
    {
        int min = i; // Reset min before starting next iteration
        for (int j = i + 1; j < size; j++)
        {
            // Find the minimum starting from index i+1
            if (A[j] < A[min])
                min = j;
        }
        // swap the minimum index (min) with the current index i
        if (min != i)
        {
            A[i] += A[min];
            A[min] = A[i] - A[min];
            A[i] -= A[min];
        }
        PrintArray(A);
    }
}

int main()
{
    int A[10] = {7, 5, 4, 2, 6, 9, 1, 3, 10, 8};
    cout << "Original array is ";
    PrintArray(A);

    SelectionSort(A);
    cout << "Sorted array using selection sort is ";
    PrintArray(A);
}