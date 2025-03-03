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

// To search an element in BST, returns true if element is found
bool Search(BstNode *root, int data)
{
    if (!root)
        return false;
    else if (data == root->data)
        return true;
    else if (data < root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int FindHeight(BstNode *root)
{
    if (!root)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

// Any node in BST should have value between a min and a max.
// If going to the left of root, the the left node should be between a min value and max=value of root
// If going to the right of root, the the right node should be between a min value=value of root and max value
bool IsBinarySearchTree(BstNode *root, int min, int max)
{
    if (!root)
        return true;
    int data = root->data;
    if (data <= max and
        data > min and
        IsBinarySearchTree(root->left, min, data) and
        IsBinarySearchTree(root->right, data, max))
    {
        return true;
    }
    else
        return false;
}

// Global to keep track of the previous value
int previousNodeValue = -10000000;
// Depth first search for a binary tree reads the list in a sorted order for In-Order Traversal (<left><read root><right>).
// So, at any given iteration the current value of the node should be greater than ot equal to the previous node value
bool IsBinarySearchTreeDFSInOrder(BstNode *root, int &previousNodeValue)
{
    if (!root)
        return true;
    if (IsBinarySearchTreeDFSInOrder(root->left, previousNodeValue) &&
        (cout << "[" << root->data << "]-->" << previousNodeValue << "-->") && root->data > previousNodeValue && (previousNodeValue = root->data) &&
        IsBinarySearchTreeDFSInOrder(root->right, previousNodeValue))
        return true;
    else
        return false;
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
    root = Insert(root, 1);
    root = Insert(root, 2);
    root = Insert(root, 3);

    cout << "IsBinarySearchTree=" << IsBinarySearchTree(root, -100000, 100000) << endl;
    cout << "IsBinarySearchTreeDFSInOrder=" << IsBinarySearchTreeDFSInOrder(root, previousNodeValue) << endl;
}