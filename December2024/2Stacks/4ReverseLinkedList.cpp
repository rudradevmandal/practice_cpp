#include <iostream>

using namespace std;

class Node; // Forward declaration
Node *head;

class Node
{
public:
    int data;
    Node *next_node;

    Node(int x) : data(x), next_node(nullptr) {};
    void Insert(int data)
    {
        Node *temp = new Node(data);
        temp->next_node = head;
        head = temp;
    }
    void Delete()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next_node;
        delete temp;
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

void ReverseLinkedList()
{
    stack<Node *> s;
    while (head)
    {
        s.push(head);
        head = head->next_node;
    }
    head = s.top();
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        temp->next_node = s.top();
    }
}

int main()
{

    head = nullptr;
    head->Insert(2);
    head->Insert(3);
    head->Insert(5);
    head->Insert(9);
    head->Insert(30);
    head->Insert(1);
    head->Print(head);
    ReverseLinkedList();
    head->Print(head);
}