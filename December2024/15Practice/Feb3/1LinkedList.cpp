#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int x) : data(x), next(nullptr) {}
};

Node *head;

void Print()
{
    Node *current = head;
    cout << "START-->";
    while (current)
    {
        cout << "[" << current->data << "]-->";
        current = current->next;
    }
    cout << "END" << endl;
}

void Insert(int x)
{
    Node *newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

void Delete()
{
    if (!head)
        return;
    Node *nodeToBeDeleted = head;
    head = head->next;
    delete nodeToBeDeleted;
}

void Reverse()
{
    if (!head)
        return;
    Node *next = nullptr;
    Node *prev = nullptr;
    Node *current = head;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    head = nullptr;
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    Reverse();
    Print();
}