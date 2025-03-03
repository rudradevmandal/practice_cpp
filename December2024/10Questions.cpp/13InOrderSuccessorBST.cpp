#include <iostream>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;

    // constructor
    BstNode(int x) : data(x), left(nullptr), right(nullptr) {};
};

void PrintBFS(BstNode *current)
{
    queue<BstNode *> Q;
    Q.push(current);

    while (!Q.empty())
    {
        BstNode *front = Q.front();
        cout << "[" << front->data << "]-->";
        if (front->left)
            Q.push(front->left);
        if (front->right)
            Q.push(front->right);
        Q.pop();
    }
}

BstNode *Insert(BstNode *current, int x)
{
    if (!current)
    {
        current = new BstNode(x);
        return current;
    }

    if (x <= current->data)
        current->left = Insert(current->left, x);
    else
        current->right = Insert(current->right, x);
    return current;
}

void Print(BstNode *current)
{
    if (!current)
        return;
    Print(current->left);
    cout << "[" << current->data << "]-->";
    Print(current->right);
}

int check = -1;
int result = -1;

// Bruteforce technique - O(n)
int InOrderSuccessor(BstNode *current, int x)
{
    if (!current)
        return -1;
    InOrderSuccessor(current->left, x);
    if (check == x)
    {
        result = current->data;
        check = -1;
    }

    if (x == current->data)
        check = current->data;
    InOrderSuccessor(current->right, x);
    return result;
}
BstNode *Search(BstNode *root, int x)
{
    if (!root)
        return nullptr;
    if (x < root->data)
        return Search(root->left, x);
    else if (x > root->data)
        return Search(root->right, x);
    else
        return root;
}

BstNode *GetMin(BstNode *root)
{
    if (!root->left)
        return root;
    return GetMin(root->left);
}

// InOrder reading is done as <left><read><right> -- O(height of BST)
// First go to the leftest node of the current node. Then read the current node and then go right.
// At any point if a node is read, it means all its left subtree is read. So, always ignore left subtree.

// If the node in question has right sub tree. Then the next read node shall be the minimum of the the right sub tree
// If no right subtree is present, then the node previous to the current node shall be read. But the current node should be to the right of the previous node.
BstNode *InOrderSuccessorBST(BstNode *root, int x)
{
    BstNode *current = Search(root, x);
    if (!current)
        return nullptr;

    // Case 1: If right subtree
    if (current->right)
        return GetMin(current->right);
    // Case 2: If no right subtree - Then find a previous node for which the current node is at right
    else
    {
        BstNode *ancestor = root;
        BstNode *successor = nullptr;

        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
    return nullptr;
}

int main()
{
    BstNode *root = nullptr;
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 17);
    root = Insert(root, 1);
    root = Insert(root, 3);
    root = Insert(root, 6);
    root = Insert(root, 9);
    root = Insert(root, 11);
    root = Insert(root, 13);
    root = Insert(root, 16);
    root = Insert(root, 18);
    Print(root);
    cout << endl;

    int x = 6;
    cout << "InOrder successor of x=" << x << " is " << InOrderSuccessor(root, x) << endl;
    BstNode *s = InOrderSuccessorBST(root, x);
    cout << "InOrder successor of x=" << x << " is " << (s ? s->data : -1) << endl;
}