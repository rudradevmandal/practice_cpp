#include <iostream>
using namespace std;

void PrintMaxSumSubArray(int *A, int size)
{
    int currentSum = 0;
    int maxSum = 0;
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < size; i++)
    {
        // Case 1: When Array starts with negative number (Assume that complete array is negative)
        //  In that case, the highest value in the array is the max sum
        if (i == 0 and A[0] < 0)
        {
            maxSum = A[0];
            while (i < size)
            {
                // If encountered a positive number
                if (A[i] > 0)
                {
                    currentSum = A[i];
                    maxSum = currentSum;
                    minIndex = i;
                    maxIndex = i;
                    break;
                }
                else if (A[i] > maxSum) // Keep track of the negative number
                {
                    maxSum = A[i];
                    minIndex = i;
                    maxIndex = i;
                }
                i++;
            }
        }
        else
        {
            if (currentSum + A[i] > 0)
            {
                if (currentSum == 0) // Save minIndex only at first time
                    minIndex = i;
                currentSum += A[i];
                if (currentSum > maxSum)
                {
                    maxSum = currentSum;
                    maxIndex = i; // Save maxIndex while updating maxSum
                }
            }
            else
            {
                currentSum = 0;
            }
        }
    }
    for (int i = minIndex; i <= maxIndex; i++)
    {
        cout << "[" << A[i] << "], ";
    }
    cout << "Sum=" << maxSum << endl;
}
int main()
{
    int x;
    int A[10] = {-1, -3, -2, -5, -7, -6, -1, -4, -11, -18};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    PrintMaxSumSubArray(A, size);
}