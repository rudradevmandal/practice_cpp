#include <iostream>
using namespace std;
const int MAX = 10;
class StackA
{
    int A[MAX];
    int top;

public:
    StackA() : top(-1) {}
    void Push(int x)
    {
        if ((top + 1) == MAX)
        {
            cout << "Error: Stack Overflow" << endl;
            return;
        }

        A[++top] = x;
        Print();
    }

    void Pop()
    {
        if (top == -1) // No Element
        {
            cout << "Error: Stack Underflow" << endl;
            return;
        }

        top--;
        Print();
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Error: No elements in stack." << endl;
            return INT_MIN;
        }
        return A[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void Print()
    {
        cout << "End-->";
        if (top != -1)
        {
            for (int i = 0; i <= top; i++)
            {
                cout << "[" << A[i] << "]-->";
            }
        }
        cout << "Start" << endl;
    }
};
class Node
{
public:
    int data;
    Node *next_node;
    Node(int x) : data(x), next_node(nullptr) {}
};

class StackL
{
    Node *top;

public:
    StackL() : top(nullptr) {}
    void Push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next_node = top;
        top = newNode;
        Print();
    }

    void Pop()
    {
        if (!top)
        {
            cout << "Error: No elements in stack." << endl;
            return;
        }
        Node *nodeToBeDeleted = top;
        top = top->next_node;
        delete nodeToBeDeleted;
        Print();
    }

    int Top()
    {
        if (!top)
        {
            cout << "Error: No elements in stack." << endl;
            return 0;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void Print()
    {
        Node *current = top;
        cout << "Start-->";
        while (current)
        {
            cout << "[" << current->data << "]-->";
            current = current->next_node;
        }
        cout << "End" << endl;
    }
};

int main()
{
    StackL Sa;
    Sa.Push(1);
    cout << "isEmpty=" << Sa.isEmpty() << endl;
    Sa.Push(2);
    Sa.Push(3);
    Sa.Push(4);
    Sa.Push(5);
    Sa.Push(6);
    Sa.Push(7);
    Sa.Push(8);
    Sa.Push(9);
    Sa.Push(10);
    Sa.Push(11);
    Sa.Push(12);
    Sa.Push(13);

    cout << "Top=" << Sa.Top() << endl;

    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();

    cout << "isEmpty=" << Sa.isEmpty() << endl;
    Sa.Push(11);
    Sa.Push(12);
    Sa.Push(13);
    cout << "Top=" << Sa.Top() << endl;
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    cout << "isEmpty=" << Sa.isEmpty() << endl;
    Sa.Pop();

    cout << "isEmpty=" << Sa.isEmpty() << endl;
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    Sa.Pop();
    cout << "isEmpty=" << Sa.isEmpty() << endl;
}