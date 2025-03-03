#include <iostream>
using namespace std;

// Definition of Node for Binary search tree
class BstNode
{
public:
    int data;
    BstNode *left;
    BstNode *right;
    BstNode(int x) : data(x), left(nullptr), right(nullptr) {};
};

// Function to create a new Node in heap
BstNode *GetNewNode(int data)
{
    return new BstNode(data);
}

// To insert data in BST, returns address of root node
BstNode *Insert(BstNode *root, int data)
{
    if (!root)
        root = GetNewNode(data);
    // if data to be inserted is lesser, insert in left subtree.
    else if (data < root->data)
        root->left = Insert(root->left, data);
    // else, insert in right subtree.
    else
        root->right = Insert(root->right, data);
    return root;
}

void PrintDFSInorder(BstNode *root)
{
    if (!root)
        return;

    PrintDFSInorder(root->left);
    cout << "[" << root->data << "]-->";
    PrintDFSInorder(root->right);
}

BstNode *Search(BstNode *root, int data)
{
    if (!root)
        return nullptr;
    else if (data == root->data)
        return root;
    else if (data < root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

BstNode *FindMin(BstNode *root)
{
    if (!root->left)
        return root;
    else
        return FindMin(root->left);
}

BstNode *FindInroderSuccessor(BstNode *root, int data)
{
    // Search the Tree - O(height)
    BstNode *current = Search(root, data);

    if (!current)
        return nullptr;

    // Case 1: Node has right tree - The next value should be the minimum of the right sub-tree
    if (current->right)
    {
        return FindMin(current->right);
    }
    // Case 2: No right subtree - Find the previous (ancestor) node whose left node is the ancestor for the current node
    else
    {
        BstNode *ancestor = root;
        BstNode *successor = nullptr;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor; // Deepest node for which we took left before reaching the current node
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
    return nullptr;
}

int main()
{
    BstNode *root = nullptr;
    /*Code to test the logic*/
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 11);
    root = Insert(root, 13);
    cout << "****************** DFS - INORDER ******************" << endl;
    PrintDFSInorder(root);

    int x = 13;
    cout << "****************** DFS - INORDER SUCCESSOR ******************" << endl;
    BstNode *result = FindInroderSuccessor(root, x);
    cout << "Inorder successor for x=" << x << " is " << (result ? result->data : -1) << endl;
}