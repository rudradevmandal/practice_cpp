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

void BubbleSort(int (&A)[10])
{
    int size = sizeof(A) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        bool isSwap = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            // Swap if current index is greater than lower
            if (A[j] > A[j + 1])
            {
                A[j] += A[j + 1];
                A[j + 1] = A[j] - A[j + 1];
                A[j] -= A[j + 1];
                isSwap = true;
            }
        }
        // If no swap was performed in the last iteration i.e, array is sorted. Break here.
        if (!isSwap)
            break;
        PrintArray(A);
    }
}

int main()
{
    int A[10] = {7, 5, 4, 2, 6, 9, 1, 3, 10, 8};
    cout << "Original array is ";
    PrintArray(A);

    BubbleSort(A);
    cout << "Sorted array using Bubble sort is ";
    PrintArray(A);
}