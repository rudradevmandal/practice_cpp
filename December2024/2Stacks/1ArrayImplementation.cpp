#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

class Stack
{
    int A[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}
    void Push(int data)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Error: Stack Overflow" << endl;
            return;
        }
        A[++top] = data;
    }

    void Pop()
    {
        if (top == -1)
        {
            cout << "Error: No elements in Stack!" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Error: No elements in Stack!" << endl;
            return 0;
        }
        return A[top];
    }

    bool IsEmpty()
    {
        return top == -1 ? true : false;
    }
    void Print()
    {
        cout << "Start-->";
        for (int i = 0; i <= top; i++)
            cout << "[" << A[i] << "]-->";
        cout << "End" << endl;
    }
};

int main()
{
    Stack S;
    cout << "Top=[" << S.Top() << "]" << endl;
    S.Push(1);
    S.Push(2);
    S.Push(13);
    S.Push(4);
    S.Push(5);
    S.Push(6);
    S.Print();

    S.Pop();
    S.Print();
    S.Pop();
    S.Print();
    S.Pop();
    S.Print();

    cout << "Top=[" << S.Top() << "]" << endl;
}