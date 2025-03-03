#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next_node;
    Node *prev_node;
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
void PrintReverse(Node *head)
{
    cout << "END-->";
    while (head->next_node)
    {
        head = head->next_node;
    }
    while (head)
    {
        cout << "[" << head->data << "]-->";
        head = head->prev_node;
    }
    cout << "START" << endl;
}
void InsertAtN(int data, int position)
{
    if (position <= 0)
    {
        cout << "Wrong position entered" << endl;
        return;
    }
    Node *temp = new Node();
    temp->data = data;
    Node *current = head;
    if (position == 1)
    {
        temp->next_node = head;
        if (head)
            head->prev_node = temp; // Link next node's previous to new Node
        temp->prev_node = nullptr;
        head = temp;
        Print(head);
        return;
    }

    for (int i = 1; i < position - 1; i++)
    {
        current = current->next_node;
        if (!current)
        {
            cout << "Wrong Position Entered. List of size=" << i << endl;
            return;
        }
    }
    temp->next_node = current->next_node; // Link new Node next to current's next
    if (current->next_node)
        current->next_node->prev_node = temp; // Link next node's previous to new Node
    temp->prev_node = current;                // Link new node's previous to current node
    current->next_node = temp;                // Link current node's next to new node
    Print(head);
}

void DeleteAtN(int position)
{
    cout << "Delete at position=" << position << endl;
    if (position <= 0)
    {
        cout << "Wrong position entered" << endl;
        return;
    }
    Node *current = head;
    if (position == 1)
    {
        current->next_node->prev_node = nullptr;
        head = current->next_node;
        delete current;
        Print(head);
        return;
    }

    for (int i = 1; i < position; i++)
    {
        current = current->next_node;
        if (!current)
        {
            cout << "Wrong Position Entered. List of size=" << i << endl;
            return;
        }
    }
    if (current->next_node)
        current->next_node->prev_node = current->prev_node;
    current->prev_node->next_node = current->next_node;
    delete current;
    Print(head);
}

int main()
{
    head = nullptr;
    InsertAtN(1, 1);
    InsertAtN(2, 2);
    InsertAtN(3, 3);
    InsertAtN(4, 4);
    InsertAtN(5, 5);
    InsertAtN(333, 5);
    InsertAtN(666, 2);
    InsertAtN(777, 1);
    InsertAtN(888, 9);

    cout << "****************** REVERSE - PRINT ******************" << endl;
    PrintReverse(head);

    cout << "****************** DELTETE ******************" << endl;
    DeleteAtN(1);
    DeleteAtN(2);
    DeleteAtN(5);
    DeleteAtN(4);
    DeleteAtN(5);
    DeleteAtN(6);

    cout << "****************** REVERSE - PRINT ******************" << endl;
    PrintReverse(head);
}