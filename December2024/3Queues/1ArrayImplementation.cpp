#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

class Queue
{
    int A[MAX_SIZE];
    int front;
    int end;

public:
    Queue() : front(-1), end(-1) {};

    // To check wheter Queue is empty or not
    bool isEmpty()
    {
        return (front == -1 && end == -1);
    }

    // To check whether Queue is full or not
    bool isFull()
    {
        return ((end + 1) % MAX_SIZE == front);
    }

    // Inserts an element in queue at rear end
    void Enqueue(int data)
    {
        // If reached end of array and some cells are dequed from from a some time.
        // Check if we can re-use the cell from index 0->front.
        if (isFull())
        {
            cout << "Error: Overflow." << endl;
            return;
        }
        if (front == -1)
            front++;
        end = (end + 1) % MAX_SIZE;
        A[end] = data;
        Print();
    }

    // Removes an element in Queue from front end.
    int Dequeue()
    {
        if (isEmpty())
        {
            cout << "Error: No elements to dequeue." << endl;
            return 0;
        }
        int a = A[front];
        if (front == end)
        {
            front = end = -1;
            return a;
        }
        front = (front + 1) % MAX_SIZE;
        return a;
    }

    // Returns element at front of queue.
    int Front()
    {
        if (front == -1)
        {
            cout << "Error: No elements in queue." << endl;
            return 0;
        }
        return A[front];
    }

    void Print()
    {
        cout << "START-->";
        int i = front;
        while (i != end)
        {
            cout << "[" << A[i] << "]-->";
            i = (i + 1) % MAX_SIZE;
        }
        cout << "END" << endl;
    }
};

int main()
{
    std::cout << "***Queue: Circular Array implementation***" << std::endl;
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(21);
    q.Dequeue();
    q.Print();
    q.Enqueue(30);
    q.Enqueue(40);
    std::cout << "q.Front()=" << q.Front() << ", s.isEmpty()=" << q.isEmpty() << std::endl;
    q.Dequeue();
    q.Print();
    q.Dequeue();
    q.Print();
    q.Dequeue();
    q.Print();
    q.Dequeue();
    q.Print();
    std::cout << "q.Front()=" << q.Front() << ", s.isEmpty()=" << q.isEmpty() << std::endl;
}
