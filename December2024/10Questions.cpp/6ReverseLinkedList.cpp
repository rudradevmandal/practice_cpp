#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next_node;
    Node(int data) : data(data), next_node(nullptr) {};
};

Node *head;

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

void Insert(Node **head, int x)
{
    Node *newNode = new Node(x);
    Node *temp = (*head);
    (*head) = newNode;
    newNode->next_node = temp;
}

Node *Reverse(Node *current)
{
    if (!(current)->next_node)
    {
        head = current;
        return current;
    }

    Node *temp = Reverse(current->next_node);
    temp->next_node = current;
    current->next_node = nullptr;
    return current;
}

int main()
{
    head = nullptr;
    Insert(&head, 1);
    Insert(&head, 2);
    Insert(&head, 3);
    Insert(&head, 4);
    Insert(&head, 5);
    Print(head);

    cout << "=================== REVERSED ===================" << endl;
    Reverse(head);
    Print(head);
}