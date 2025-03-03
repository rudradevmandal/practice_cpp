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
void Insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next_node = head;
    head = temp;
    Print(head);
}
void DeleteAtN(int position)
{
    cout << "Delete at position=" << position << endl;
    if (position <= 0)
    {
        cout << "Wrong position entered." << endl;
        return;
    }

    Node *temp = head;
    if (position == 1)
    {
        head = head->next_node;
        delete temp;
        Print(head);
        return;
    }
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next_node;
        if (!temp)
        {
            cout << "Wrong Position Entered. List of size=" << i << endl;
            return;
        }
    }
    Node *nodeToBeDeleted = temp->next_node;
    temp->next_node = nodeToBeDeleted->next_node;
    delete nodeToBeDeleted;
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

    cout << "******************Delete******************" << endl;
    DeleteAtN(3);
    DeleteAtN(2);
    DeleteAtN(1);
    DeleteAtN(0);
    DeleteAtN(3);
}