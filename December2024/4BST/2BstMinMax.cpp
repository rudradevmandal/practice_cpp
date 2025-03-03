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

int FindMin(BstNode *root)
{
    if (!root)
        return -1;
    if (!root->left)
        return root->data;
    return FindMin(root->left);
}

int FindMax(BstNode *root)
{
    if (!root)
        return -1;
    if (!root->right)
        return root->data;
    return FindMax(root->right);
}

int main()
{
    BstNode *root = nullptr;
    /*Code to test the logic*/
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 1);
    root = Insert(root, 8);
    root = Insert(root, 120);
    // Ask user to enter a number.
    int number;
    cout << "Min=" << FindMin(root) << endl;
    cout << "Max=" << FindMax(root) << endl;
}