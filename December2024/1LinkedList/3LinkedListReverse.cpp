#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next_node;
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
void PrintRecursion(Node *head)
{
    if (!head)
    {
        cout << "END" << endl;
        return;
    }
    cout << "[" << head->data << "]-->";
    PrintRecursion(head->next_node);
}
void PrintRecursionReverse(Node *head)
{
    if (!head)
    {
        cout << "START-->";
        return;
    }
    PrintRecursionReverse(head->next_node);
    cout << "[" << head->data << "]-->";
}
void Insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next_node = head;
    head = temp;
    Print(head);
}
void ReverseManual()
{
    Node *current = head;
    Node *previous = nullptr;
    Node *next = nullptr;

    while (current)
    {
        next = current->next_node;     // Save the next node
        current->next_node = previous; // Change the link to previous node
        previous = current;            // Save the current node as previous node
        current = next;                // Move to the next node
    }
    head = previous;
    Print(head);
}
void ReveseRecursion(Node *current)
{
    if (!current->next_node)
    {
        head = current;
        return;
    }
    Node *next = current->next_node;
    ReveseRecursion(next); // Move to the next node
    next->next_node = current;
    current->next_node = nullptr;
    Print(head);
}
int main()
{
    head = nullptr;
    Insert(2);
    Insert(3);
    Insert(5);
    Insert(9);
    Insert(30);
    Insert(1);

    cout << "****************** REVERSE - ITERATIVE ******************" << endl;
    ReverseManual();
    cout << "****************** PRINT - RECURSION ******************" << endl;
    PrintRecursion(head);
    cout << "****************** PRINT - RECURSION - REVERSE ******************" << endl;
    PrintRecursionReverse(head);
    cout << "****************** REVERSE - RECURSION ******************" << endl;
    ReveseRecursion(head);
    Print(head);
}