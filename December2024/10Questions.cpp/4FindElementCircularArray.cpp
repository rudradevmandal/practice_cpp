#include <iostream>
using namespace std;

int FindNumber(int *A, int size, int x)
{

    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // cout << "low=" << low << ", Alow=" << A[low] << ", high=" << high << ", Ahigh=" << A[high] << ", mid=" << mid << ", Amid=" << A[mid] << endl;
        if (A[mid] == x)
            return mid + 1;

        if (A[low] <= A[mid])
        {
            if (x < A[mid] and x >= A[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (A[high] >= A[mid])
        {
            if (x <= A[high] and x > A[mid])
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
    // int A[10] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    // int A[10] = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    // int A[10] = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int A[10] = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
    // int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;
    cout << x << " occurs at " << FindNumber(A, size, x) << endl;
}