#include <iostream>
using namespace std;

class BSTNode
{
public:
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int x) : data(x), left(nullptr), right(nullptr) {};
};

BSTNode *Insert(BSTNode *root, int x)
{
    if (!root)
    {
        return new BSTNode(x);
    }
    if (x < root->data)
        root->left = Insert(root->left, x);
    else
        root->right = Insert(root->right, x);
    return root;
}

BSTNode *Search(BSTNode *root, int x)
{
    while (root)
    {
        if (x < root->data)
            root = root->left;
        else if (x > root->data)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}

void PrintBFS(BSTNode *root)
{
    queue<BSTNode *> Q;
    Q.push(root);

    cout << "Start-->";
    while (!Q.empty())
    {
        BSTNode *current = Q.front();
        cout << "[" << current->data << "]-->";
        if (current->left)
            Q.push(current->left);
        if (current->right)
            Q.push(current->right);
        Q.pop();
    }
    cout << "End" << endl;
}

void PrintDfsPreOrder(BSTNode *root)
{
    if (!root)
        return;

    cout << "[" << root->data << "]-->";
    PrintDfsPreOrder(root->left);
    PrintDfsPreOrder(root->right);
}

void PrintDfsInOrder(BSTNode *root)
{
    if (!root)
        return;

    PrintDfsInOrder(root->left);
    cout << "[" << root->data << "]-->";
    PrintDfsInOrder(root->right);
}

void PrintDfsPostOrder(BSTNode *root)
{
    if (!root)
        return;

    PrintDfsPostOrder(root->left);
    PrintDfsPostOrder(root->right);
    cout << "[" << root->data << "]-->";
}

BSTNode *FindMin(BSTNode *root)
{
    if (!root->left)
        return root;
    root = FindMin(root->left);
    return root;
}

BSTNode *FindMax(BSTNode *root)
{
    if (!root->right)
        return root;
    root = FindMax(root->right);
    return root;
}

bool IsBst(BSTNode *root, int min, int max)
{
    if (!root)
        return true;
    if (root->data <= max and root->data >= min and
        IsBst(root->left, min, root->data) and
        IsBst(root->right, root->data, max))
    {
        return true;
    }
    else
        return false;
}

int Max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int FindHeight(BSTNode *root)
{
    if (!root)
        return -1;
    return Max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

BSTNode *Delete(BSTNode *root, int x)
{
    if (!root)
        return root;
    else if (x < root->data)
        root->left = Delete(root->left, x);
    else if (x > root->data)
        root->right = Delete(root->right, x);
    else
    {
        // Case 1: No child
        if (!root->left and !root->right)
        {
            delete root;
            return nullptr;
        }
        // Case 2: only left child
        else if (root->left and !root->right)
        {
            BSTNode *temp = root;
            // copy the next left child's content
            root = root->left;
            delete temp;
        }
        // Case 3: only right child
        else if (root->right and !root->left)
        {
            BSTNode *temp = root;
            // copy the next right child's content
            root = root->right;
            delete temp;
        }
        // Case 4: Both children
        else
        {
            BSTNode *newNode = FindMax(root->left);
            root->data = newNode->data;
            root->left = Delete(root->left, newNode->data);
        }
    }
    return root;
}

BSTNode *InOrderSuccessor(BSTNode *root, int x)
{
    if (!root)
        return nullptr;
    BSTNode *current = Search(root, x);
    // Case 1: If right child is present
    if (current->right)
    {
        return FindMin(current->right);
    }
    // Case 2: If no right child is present
    else
    {
        BSTNode *successor = root;
        BSTNode *ancestor = root;

        while (ancestor != current)
        {
            if (x < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main()
{
    BSTNode *root = nullptr;
    /*Code to test the logic*/
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 23);
    root = Insert(root, 22);
    root = Insert(root, 21);
    root = Insert(root, 28);
    root = Insert(root, 29);
    // Ask user to enter a number.
    // int number;
    // cout << "Enter number be searched\n";
    // cin >> number;
    // If number is found, print "FOUND"
    // if (Search(root, number))
    //     cout << "Found\n";
    // else
    //     cout << "Not Found\n";

    cout << "========================= Print BFS =========================" << endl;
    PrintBFS(root);

    cout << "========================= Print DFS Pre-Order =========================" << endl;
    cout << "Start-->";
    PrintDfsPreOrder(root);
    cout << "End" << endl;

    cout << "========================= Print DFS In-Order =========================" << endl;
    cout << "Start-->";
    PrintDfsInOrder(root);
    cout << "End" << endl;

    cout << "========================= Print DFS Post-Order =========================" << endl;
    cout << "Start-->";
    PrintDfsPostOrder(root);
    cout << "End" << endl;

    cout << "Min=" << FindMin(root)->data << endl;
    cout << "Max=" << FindMax(root)->data << endl;
    cout << "IsBst=" << IsBst(root, INT_MIN, INT_MAX) << endl;
    cout << "Height=" << FindHeight(root) << endl;

    cout << "========================= Delete =========================" << endl;
    Delete(root, 12);
    cout << "========================= Print DFS In-Order =========================" << endl;
    cout << "Start-->";
    PrintDfsInOrder(root);
    cout << "End" << endl;
    cout << "========================= Delete =========================" << endl;
    Delete(root, 22);
    cout << "========================= Print DFS In-Order =========================" << endl;
    cout << "Start-->";
    PrintDfsInOrder(root);
    cout << "End" << endl;
    cout << "========================= Delete =========================" << endl;
    Delete(root, 20);
    cout << "========================= Print DFS In-Order =========================" << endl;
    cout << "Start-->";
    PrintDfsInOrder(root);
    cout << "End" << endl;
    cout << "========================= Delete =========================" << endl;
    Delete(root, 15);
    cout << "========================= Print DFS In-Order =========================" << endl;
    cout << "Start-->";
    PrintDfsInOrder(root);
    cout << "End" << endl;

    int x = 10;
    cout << "Inorder successor of " << x << " is " << InOrderSuccessor(root, x)->data << endl;
}