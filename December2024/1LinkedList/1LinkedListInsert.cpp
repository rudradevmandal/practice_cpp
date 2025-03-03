#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next_node;

public:
    void InsertAtStart(Node **pointerToHead, int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next_node = *pointerToHead;
        *pointerToHead = temp;
        (*pointerToHead)->Print();
    }

    void InsertAtN(Node **pointerToHead, int data, int position)
    {
        Node *temp = new Node();
        Node *current = *(pointerToHead);
        temp->data = data;

        if (position <= 0)
        {
            cout << "Wrong Position Entered." << endl;
            return;
        }

        if (position == 1)
        {
            InsertAtStart(pointerToHead, data);
            return;
        }

        // Stop at one position before inserting as next node should be the new node
        for (int i = 1; i < position - 1; i++)
        {
            current = current->next_node;
            if (!current)
            {
                cout << "Wrong Position Entered. List of size=" << i << endl;
                return;
            }
        }
        temp->next_node = current->next_node;
        current->next_node = temp;
        (*pointerToHead)->Print();
    }

    void Print()
    {
        Node *temp = this;
        cout << "START-->";
        while (temp)
        {
            cout << "[" << temp->data << "]-->";
            temp = temp->next_node;
        }
        cout << "END" << endl;
    }
};

Node *head;
int main()
{
    head = nullptr; // head Node
    std::cout << "How many numbers?" << std::endl;
    int n, x;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the numbers:" << std::endl;
        std::cin >> x;
        head->InsertAtStart(&head, x);
    }
    head->InsertAtN(&head, 998, 2);
}