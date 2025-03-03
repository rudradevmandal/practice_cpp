#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next_node;

    Node(int x) : data(x), next_node(nullptr) {}
    void setNextNode(Node *next) { this->next_node = next; }
    int getValue() { return this->data; }
    Node *getNextNode() { return this->next_node; }
};

Node *head; // Head of the linked list

void Print(Node *head)
{
    cout << "START-->";
    while (head)
    {
        cout << "[" << head->getValue() << "]-->";
        head = head->getNextNode();
    }
    cout << "END" << endl;
}

void InsertAtStart(int x)
{
    Node *nodeInsert = new Node(x);
    nodeInsert->setNextNode(head);
    head = nodeInsert;
    Print(head);
}

void InsertAtEnd(int x)
{
    if (!head) // Insert at first
    {
        return InsertAtStart(x);
    }
    Node *nodeInsert = new Node(x);
    Node *current = head;
    while (current->getNextNode())
    {
        current = current->getNextNode();
    }
    current->setNextNode(nodeInsert);
    Print(head);
}

void InsertAtN(int x, int position)
{
    if (position <= 0)
    {
        cout << "Wrong position entered." << endl;
        return;
    }
    // If position is 1 - Insert at Start
    if (position == 1)
    {
        return InsertAtStart(x);
    }
    Node *current = head;
    // Iterate till the previous node as previousNode->next_node=NodeToBeInserted
    for (int i = 0; i < position - 2; i++)
    {
        if (!current)
        {
            cout << "Wrong position entered." << endl;
            return;
        }
        current = current->getNextNode();
    }
    if (!current->getNextNode()) // Insert at End
    {
        return InsertAtEnd(x);
    }
    Node *nodeInsert = new Node(x);
    Node *currentNext = current->getNextNode();
    current->setNextNode(nodeInsert);
    nodeInsert->setNextNode(currentNext);
    Print(head);
}

Node *Reverse(Node *current)
{
    if (!current->getNextNode())
    {
        head = current;
        return current;
    }

    current->next_node = Reverse(current->next_node);
    current->next_node->next_node = current;
    current->next_node = nullptr;
    return current;
}

void CreateLoop(Node *current)
{
    Node *end = nullptr;
    while (current->next_node)
    {
        current = current->next_node;
    }
    end = current;
    current = head;
    for (int i = 0; i < 2; i++)
    {
        current = current->next_node;
    }
    end->next_node = current;
}

void DetectAndRemoveLoop()
{
    if (!head or !head->next_node)
    {
        cout << "No Loop Detected." << endl;
        return;
    }

    Node *fast = head->next_node->next_node;
    Node *slow = head->next_node;
    while (fast and fast->next_node)
    {
        if (slow == fast)
            break;
        slow = slow->next_node;
        fast = fast->next_node->next_node;
    }
    if (slow == fast)
    {
        cout << "Loop Detected at " << fast->data << endl;
        slow = head;
        // If slow and fast point to head, then merging point is head. We require the last elements that loops to head.
        if (slow == fast)
        {
            while (fast->next_node != slow)
            {
                fast = fast->next_node;
            }
        }
        else
        {
            while (fast->next_node != slow->next_node)
            {
                fast = fast->next_node;
                slow = slow->next_node;
            }
        }
    }
    else
    {
        cout << "No Loop Detected." << endl;
        return;
    }
    fast->next_node = nullptr;
}

int main()
{
    head = nullptr;
    InsertAtStart(1);
    InsertAtStart(2);
    InsertAtStart(3);
    InsertAtStart(4);
    InsertAtStart(5);
    InsertAtStart(6);
    cout << "========================= Create Loop =========================" << endl;
    CreateLoop(head);
    DetectAndRemoveLoop();
    Print(head);
}