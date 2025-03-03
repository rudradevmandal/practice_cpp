#include <iostream>
using namespace std;

bool IsPair(char o, char c)
{
    if (o == '(' and c == ')')
        return true;
    if (o == '[' and c == ']')
        return true;
    if (o == '{' and c == '}')
        return true;
    return false;
}

bool IsOpen(char o)
{
    if (o == '(')
        return true;
    if (o == '[')
        return true;
    if (o == '{')
        return true;
    return false;
}

bool isBalanced(string e)
{
    stack<char> S;

    for (char c : e)
    {
        if (IsOpen(c))
            S.push(c);
        else
        {
            if (!S.empty() and IsPair(S.top(), c))
                S.pop();
            else
                return false;
        }
    }
    return S.empty();
}

int main()
{
    string expression = "{}()[]{}{({{[[]]}})}";

    cout << "The given expression " << expression << " is " << (isBalanced(expression) ? "balanced." : "NOT balanced.") << endl;
}