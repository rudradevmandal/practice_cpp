#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next_node;

public:
    Node(int x) : data(x), next_node(nullptr) {};
    void Insert(int data, Node **pointerToHead)
    {
        Node *temp = new Node(data);
        temp->next_node = *pointerToHead;
        *pointerToHead = temp;
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

class Stack
{
    Node *head;

public:
    Stack() : head(nullptr) {};
    void Push(int x)
    {
        head->Insert(x, &head);
    }
    void Pop()
    {
        head->Delete(&head);
    }
    int Top()
    {
        if (head)
            return head->GetFirstElement(&head);
        cout << "Error: No elements in Stack!" << endl;
        return 0;
    }
    bool isEmpty()
    {
        return head == nullptr ? true : false;
    }
    void Print()
    {
        head->Print(head);
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