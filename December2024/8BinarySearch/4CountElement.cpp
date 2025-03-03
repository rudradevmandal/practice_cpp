#include <iostream>
using namespace std;

int FindOccurence(int *A, int n, int x, bool f = false)
{
    int first = -2;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (A[mid] == x)
        {
            first = mid;
            if (f)
                high = mid - 1; // Keep searching towards left
            else
                low = mid + 1; // Keep searching towards right
        }
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return ++first;
}

int CountOccurence(int *A, int n, int x)
{
    int first = FindOccurence(A, n, x, true);
    int last = FindOccurence(A, n, x);
    if (first == -1 && last == -1)
        return 0;
    return last - first + 1;
}

int main()
{
    int x;
    int A[10] = {4, 4, 4, 4, 4, 4, 4, 8, 9, 10};
    int size = sizeof(A) / sizeof(int);
    cout << "Size= " << size << endl;
    cout << "Enter a number to search: ";
    cin >> x;

    cout << x << " occurs " << CountOccurence(A, size, x) << " times." << endl;
}