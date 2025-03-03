#include <iostream>
using namespace std;
const int MAX = 10;

class QueueA
{
    int first;
    int last;
    int A[MAX];

public:
    QueueA() : first(-1), last(-1) {};

    void Enqueue(int x)
    {
        if (isEmpty()) // Enqueue first element
        {
            first++;
        }
        if (last != -1 and (last + 1) % MAX == first)
        {
            cout << "Error: Queue is full." << endl;
            return;
        }
        last = (last + 1) % MAX;
        A[last] = x;
        Print();
    }

    void Dequeue()
    {
        if (isEmpty() or first == last)
        {
            first = -1;
            last = -1;
            cout << "Error: No Elements in Queue." << endl;
            return;
        }
        first = (first + 1) % MAX;
        Print();
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Error: No Elements in Queue." << endl;
            return 0;
        }
        return A[first];
    }

    int Back()
    {
        if (isEmpty())
        {
            cout << "Error: No Elements in Queue." << endl;
            return 0;
        }
        return A[last];
    }

    bool isEmpty()
    {
        return first == -1 and last == -1;
    }

    void Print()
    {
        cout << "Start-->";
        int i = first;
        int j = last;

        for (int k = 0; k < MAX; k++)
        {
            cout << "[" << A[i] << "]-->";
            if (i == j)
                break;
            i = (i + 1) % MAX;
        }
        cout << "End" << endl;
    }
};

class Node
{
public:
    int data;
    Node *next_node;
    Node(int x) : data(x), next_node(nullptr) {};
};

class QueueL
{
    Node *front;
    Node *back;

public:
    QueueL() : front(nullptr), back(nullptr) {};

    void Enqueue(int x)
    {
        Node *newNode = new Node(x);
        if (front == nullptr)
        {
            back = newNode;
            front = back;
            Print();
            return;
        }
        Node *current = front;
        while (current->next_node)
        {
            current = current->next_node;
        }
        current->next_node = newNode;
        back = newNode;
        Print();
    }

    void Dequeue()
    {
        if (!front)
        {
            cout << "Error: No Elements in Queue." << endl;
            back = nullptr;
            return;
        }
        Node *nodeToBeDeleted = front;
        front = front->next_node;
        delete nodeToBeDeleted;
        Print();
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Error: No Elements in Queue." << endl;
            return 0;
        }
        return front->data;
    }

    int Back()
    {
        if (isEmpty())
        {
            cout << "Error: No Elements in Queue." << endl;
            return 0;
        }
        return back->data;
    }

    bool isEmpty()
    {
        return front == nullptr and back == nullptr;
    }

    void Print()
    {
        Node *current = front;
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
    QueueL Q;
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(5);
    Q.Enqueue(6);
    Q.Enqueue(7);
    Q.Enqueue(8);
    Q.Enqueue(9);
    Q.Enqueue(10);
    Q.Enqueue(11);
    Q.Enqueue(12);

    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();

    cout << "Front=" << Q.Front() << endl;
    cout << "Back=" << Q.Back() << endl;
    Q.Enqueue(11);
    Q.Enqueue(12);
    Q.Enqueue(13);
    Q.Enqueue(14);
    Q.Enqueue(15);

    cout << "Front=" << Q.Front() << endl;
    cout << "Back=" << Q.Back() << endl;

    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();

    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();

    cout << "Front=" << Q.Front() << endl;
    cout << "Back=" << Q.Back() << endl;
    Q.Dequeue();

    cout << "Front=" << Q.Front() << endl;
    cout << "Back=" << Q.Back() << endl;

    Q.Dequeue();

    cout << "Front=" << Q.Front() << endl;
    cout << "Back=" << Q.Back() << endl;
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
}