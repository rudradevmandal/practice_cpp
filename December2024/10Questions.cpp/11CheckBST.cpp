#include <iostream>
using namespace std;

class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;

    // Constructor
    BstNode(int x) : data(x), left(nullptr), right(nullptr) {};
};

BstNode *root;

BstNode *Insert(BstNode *current, int x)
{
    if (!current)
    {
        current = new BstNode(x);
        return current;
    }
    if (x <= current->data)
        current->left = Insert(current->left, x);
    else if (x >= current->data)
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

int n = -1000000000;
bool isBST(BstNode *current)
{
    if (!current)
        return true;
    return isBST(current->left);
    if (n >= current->data)
        return false;
    else
        n = current->data;
    return isBST(current->right);
}

int main()
{
    root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 10);
    root = Insert(root, 6);
    root = Insert(root, 9);
    root = Insert(root, 2);
    root = Insert(root, 7);
    root = Insert(root, 4);
    root = Insert(root, 3);
    root = Insert(root, 8);
    Print(root);
    cout << endl;
    cout << "Given Binary Tree isBST=" << isBST(root) << endl;
}