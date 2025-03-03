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

BstNode *Delete(BstNode *root, int data)
{
    if (!root)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        BstNode *temp = nullptr;
        // Case 1: No child -- Delete the node
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        // Case 2.1: Only left child -- Make left child of previous root as the left child of the current root (to be deleted)
        else if ((root->left && !root->right))
        {
            BstNode *temp = root;
            root = root->left;
            delete temp;
        }
        // Case 2.2: Only right child -- Make right child of previous root as the right child of the current root (to be deleted)
        else if ((root->right && !root->left))
        {
            BstNode *temp = root;
            root = root->right;
            delete temp;
        }
        // Case 3: 2 children -- Replace the current node (to be deleted) data to the minimum of the right subtree and delete the minimum data node from the right sub tree
        //                    OR Replace the current node (to be deleted) data to the maximum of the left subtree and delete the maximum data node from the left sub tree
        else if ((root->right && root->left))
        {
            BstNode *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            return root;
        }
    }
    return root;
}

BstNode *FindMin(BstNode *root)
{
    if (!root->left)
        return root;
    return FindMin(root->left);
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
}