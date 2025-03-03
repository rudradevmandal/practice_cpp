#include <iostream>
#include <set>
using namespace std;

class Node
{
public:
    int data;
    Node *next_node;
    Node(int data) : data(data), next_node(nullptr) {};
};

Node *head1;
Node *head2;

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

Node *Insert(Node **head, int x)
{
    Node *newNode = new Node(x);
    if (!*head)
        *head = newNode;
    else
    {
        Node *current = *head;
        while (current->next_node)
            current = current->next_node;
        current->next_node = newNode;
    }
    return newNode;
}

int FindLength(Node *root)
{
    int length = 0;
    while (root)
    {
        length++;
        root = root->next_node;
    }
    return length;
}

Node *FindMergePoint(Node *L1, Node *L2)
{
    while (L1)
    {
        while (L2)
        {
            if (L1 == L2)
                return L1;
            L2 = L2->next_node;
        }
        L1 = L1->next_node;
        L2 = head2;
    }
    return nullptr;
}

Node *FindMergePointSet(Node *L1, Node *L2)
{
    set<Node *> S;
    while (L2)
    {
        S.insert(L2);
        L2 = L2->next_node;
    }
    while (L1)
    {
        if (S.find(L1) != S.end())
            return L1;
        L1 = L1->next_node;
    }
    return nullptr;
}

Node *FindMergePointLength(Node *L1, Node *L2)
{
    int length1 = FindLength(head1);
    int length2 = FindLength(head2);

    if (length1 < length2)
        for (int i = 0; i < length2 - length1; i++)
            L2 = L2->next_node;
    else
        for (int i = 0; i < length1 - length2; i++)
            L1 = L1->next_node;

    while (L1 and L2)
    {
        if (L1 == L2)
            return L2;
        L1 = L1->next_node;
        L2 = L2->next_node;
    }
    return nullptr;
}

int main()
{
    head1 = nullptr;
    Insert(&head1, 1);
    Insert(&head1, 2);
    Insert(&head1, 3);
    Insert(&head1, 4);
    Insert(&head1, 5);
    Node *merge1 = Insert(&head1, 9);
    Insert(&head1, 10);
    Print(head1);

    head2 = nullptr;
    Insert(&head2, 6);
    Insert(&head2, 7);
    Node *merge2 = Insert(&head2, 8);
    merge2->next_node = merge1;
    Print(head2);

    int length1 = FindLength(head1);
    int length2 = FindLength(head2);
    cout << "L1.length=" << length1 << ", L2.length=" << length2 << endl;

    Node *mergePoint = FindMergePoint(head1, head2);
    cout << "BRUTE: The given linked list are " << (mergePoint ? "MERGED" : "NOT MERGED") << " at " << (mergePoint ? mergePoint->data : -1) << endl;
    cout << "SET: The given linked list are " << (mergePoint ? "MERGED" : "NOT MERGED") << " at " << (mergePoint ? mergePoint->data : -1) << endl;
    cout << "LENGTH: The given linked list are " << (mergePoint ? "MERGED" : "NOT MERGED") << " at " << (mergePoint ? mergePoint->data : -1) << endl;

    // cout << "=================== REVERSED ===================" << endl;
    // Reverse(head);
    // Print(head);
}