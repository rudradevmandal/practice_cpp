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

BstNode *GetMax(BstNode *current)
{
    if (!current->right)
        return current;
    return GetMax(current->right);
}

BstNode *Delete(BstNode *current, int x)
{
    if (!current)
        return nullptr;

    if (x < current->data)
        current->left = Delete(current->left, x);
    else if (x > current->data)
        current->right = Delete(current->right, x);
    else
    {
        // Case 1: No child
        if (!current->left and !current->right)
        {
            delete current;
            return nullptr;
        }
        // Case 2: Only left child
        else if (current->left and !current->right)
        {
            BstNode *newLeft = current->left;
            delete current;
            return newLeft;
        }
        // Case 3: Only right child
        else if (!current->left and current->right)
        {
            BstNode *newRight = current->right;
            delete current;
            return newRight;
        }
        // Case 4: Both Children
        else
        {
            BstNode *toBeDeleted = GetMax(current->left);
            int toBeDeletedData = toBeDeleted->data;
            current = Delete(current, toBeDeleted->data);
            current->data = toBeDeletedData;
        }
    }
    return current;
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
    PrintBFS(root);
    cout << endl;

    // Delete
    root = Delete(root, 15);
    PrintBFS(root);
    cout << endl;
    root = Delete(root, 5);
    PrintBFS(root);
    cout << endl;
    root = Delete(root, 10);
    PrintBFS(root);
    cout << endl;
}