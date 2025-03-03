#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next_node;

public:
    Node(int x) : data(x), next_node(nullptr) {};
    void Insert(int data, Node **pointerToTail)
    {
        Node *temp = new Node(data);
        temp->next_node = nullptr;
        if (*pointerToTail)
            (*pointerToTail)->next_node = temp;
        *pointerToTail = temp;
    }
    void Delete(Node **pointerToHead)
    {
        if (!*pointerToHead)
            return;
        Node *head = *pointerToHead;
        *pointerToHead = (*pointerToHead)->next_node;
        delete head;
    }
    int GetFirstElement(Node **pointerToHead)
    {
        return (*pointerToHead)->data;
    }
    void Print(Node *head)
    {
        cout << "START-->";
        while (head)
        {
            cout << "[" << head->data << "]-->";
            head = head->next_node;
        }
        cout << "END" << endl;
    }
};

class Queue
{
    Node *head;
    Node *end;

public:
    Queue() : head(nullptr), end(nullptr) {};

    // To check wheter Queue is empty or not
    bool isEmpty()
    {
        return (head == nullptr and end == nullptr);
    }

    // Inserts an element in queue at rear end
    void Enqueue(int data)
    {
        end->Insert(data, &end);
        if (head == nullptr)
            head = end;
        Print();
    }

    // Removes an element in Queue from front end.
    int Dequeue()
    {
        if (head == nullptr)
        {
            cout << "Error: No elements to dequeue." << endl;
            return 0;
        }
        int x = head->GetFirstElement(&head);
        head->Delete(&head);
        if (head == end)
        {
            head = end = nullptr;
        }
        return x;
    }

    // Returns element at front of queue.
    int Front()
    {
        if (head == nullptr)
        {
            cout << "Error: No elements in queue." << endl;
            return 0;
        }
        return head->GetFirstElement(&head);
    }

    void Print()
    {
        head->Print(head);
    }
};

int main()
{
    std::cout << "***Queue: Linked List implementation***" << std::endl;
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
    q.Dequeue();
    std::cout << "q.Front()=" << q.Front() << ", s.isEmpty()=" << q.isEmpty() << std::endl;
}