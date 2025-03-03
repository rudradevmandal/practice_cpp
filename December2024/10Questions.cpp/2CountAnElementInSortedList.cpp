#include <iostream>
using namespace std;

int FindFirstOrLastOccurence(int *A, int size, int x, bool isFirst)
{
    int result = -2;
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x == A[mid])
        {
            result = mid;
            if (isFirst)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ++result;
}

int Count(int *A, int size, int x)
{
    int firstPosition = FindFirstOrLastOccurence(A, size, x, true);
    int lastPosition = FindFirstOrLastOccurence(A, size, x, false);

    if (firstPosition == -1)
        return 0;
    return (lastPosition - firstPosition + 1);
}

int main()
{
    int x;
    int A[10] = {1, 2, 3, 3, 5, 5, 5, 8, 10, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;
    cout << x << " occurs " << Count(A, size, x) << " times." << endl;
}