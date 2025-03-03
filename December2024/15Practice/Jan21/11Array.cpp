#include <iostream>
using namespace std;
void PrintMaxSumSubArray(int *A, int size)
{
    int maxSum = 0;
    int currentSum = 0;
    int low = 0;
    int high = 0;

    if (A[0] < 0) // Assume the whole array is less than zero
    {
        maxSum = A[0];
        for (int i = 0; i < size; i++)
        {
            if (A[i] > 0)
            {
                maxSum = A[i];
                break;
            }
            if (A[i] > maxSum)
            {
                maxSum = A[i];
                low = i;
                high = i;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        currentSum += A[i];
        if (currentSum > 0)
        {
            if (currentSum > maxSum)
            {
                high = i;
                maxSum = currentSum;
            }
        }
        else
        {
            currentSum = 0;
            low = i + 1;
        }
    }
    cout << "Max Sub-Array is Start-->";
    for (int i = low; i <= high; i++)
    {
        cout << "[" << A[i] << "]-->";
    }
    cout << "End" << endl;
    cout << "Max Sub-Array Sum is " << maxSum << endl;
}
int main()
{
    int x;
    int A[5] = {-5, -4, -1, -7, -8};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    PrintMaxSumSubArray(A, size);
}