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

void PrintDFSPreorder(BstNode *root)
{
    if (!root)
        return;

    cout << "[" << root->data << "]-->";
    PrintDFSPreorder(root->left);
    PrintDFSPreorder(root->right);
}

void PrintDFSInorder(BstNode *root)
{
    if (!root)
        return;

    PrintDFSInorder(root->left);
    cout << "[" << root->data << "]-->";
    PrintDFSInorder(root->right);
}

void PrintDFSPostorder(BstNode *root)
{
    if (!root)
        return;

    PrintDFSPostorder(root->left);
    PrintDFSPostorder(root->right);
    cout << "[" << root->data << "]-->";
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
    cout << "****************** DFS - PREORDER ******************" << endl;
    PrintDFSPreorder(root);
    cout << "****************** DFS - INORDER ******************" << endl;
    PrintDFSInorder(root);
    cout << "****************** DFS - POSTORDER ******************" << endl;
    PrintDFSPostorder(root);
}