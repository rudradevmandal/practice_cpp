#include <iostream>
using namespace std;

void Print(int A[4][4], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

void PrintSpiral(int *A, int a, int b)
{
    int count = 0;
    int maxElements = a * b;

    int i = 0;
    int j = 0;

    int iMax = a - 1;
    int jMax = b - 1;
    int iMin = 0;
    int jMin = 0;

    int itr = 0;

    while (count < maxElements)
    {
        // cout << "1 i=" << i << ", j=" << j << endl;
        // cout << "1 iMax=" << iMax << ", jMax=" << jMax << endl;
        // cout << "1 iMin=" << iMin << ", jMin=" << jMin << endl;
        if (i == iMin)
        {
            for (j = jMin; j <= jMax; j++)
            {
                cout << *((A + i * b) + j) << "-->";
                count++;
            }
            iMin = ++i;
            j--;
        }
        if (i == iMax)
        {
            for (j = jMax; j >= jMin; j--)
            {
                cout << *((A + i * b) + j) << "-->";
                count++;
            }
            iMax = --i;
            j++;
        }
        if (j == jMin)
        {
            for (i = iMax; i >= iMin; i--)
            {
                cout << *((A + i * b) + j) << "-->";
                count++;
            }
            jMin = ++j;
            i++;
        }
        if (j == jMax)
        {
            for (i = iMin; i <= iMax; i++)
            {
                // cout << "i=" << i << ", j=" << j << "-->";
                cout << *((A + i * b) + j) << "-->";
                count++;
            }
            jMax = --j;
            i--;
        }
    }
    cout << endl;
}

int main()
{
    int A[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Print(A, 4, 4);
    PrintSpiral((int *)A, 4, 4);
}