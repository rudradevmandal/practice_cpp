#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next_node;

    Node(int x) : data(x), next_node(nullptr) {};
};

void Print(Node *head)
{
    cout << "START-->";
    while (head)
    {
        cout << "[" << head->data << "]-->";
        head = head->next_node;
    }
    cout << "End" << endl;
}

Node *head;

void Insert(Node **head, int x)
{
    Node *newNode = new Node(x);
    newNode->next_node = *head;
    *head = newNode;
}

void PrintRecursion(Node *head)
{
    if (!head)
    {
        cout << "End" << endl;
        return;
    }
    cout << "[" << head->data << "]-->";
    PrintRecursion(head->next_node);
}

int main()
{
    head = nullptr;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 4);
    Insert(&head, 5);
    Insert(&head, 6);
    Print(head);
    cout << "Start-->";
    PrintRecursion(head);
}