#include <iostream>
using namespace std;

bool isOpenParanthesis(char p)
{
    if (p == '(' || p == '[' || p == '{')
        return true;
    return false;
}

bool isCloseParanthesis(char p)
{
    if (p == ')' || p == ']' || p == '}')
        return true;
    return false;
}

bool isoperator(char o)
{
    if (o == '*' || o == '/' || o == '+' || o == '-')
        return true;
    return false;
}

int GetOperatorWeight(char o)
{
    switch (o)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return -1;
    }
    return -1;
}
bool isHigherOrderOperator(char o1, char o2)
{
    int w1 = GetOperatorWeight(o1);
    int w2 = GetOperatorWeight(o2);
    if (w1 == w2)
    {
        if (o2 == '+' || o2 == '-')
            return true;
        return false;
    }
    return w1 > w2 ? true : false;
}

string InfixToPostfix(string e)
{
    // Declaring a Stack from Standard template library in C++.
    stack<char> s;
    string result;

    for (int i = 0; i < e.length(); i++)
    {
        // If opening bracket, push to stack
        if (isOpenParanthesis(e[i]))
        {
            s.push(e[i]);
        }
        // If closing bracket - Evaluate the stack till opening bracket
        else if (isCloseParanthesis(e[i]))
        {
            while (!isOpenParanthesis(s.top()))
            {
                result += s.top();
                s.pop();
            }
            // and then pop the opening bracket from stack
            s.pop();
        }
        // If operator, empty the stack till higher order operators are encountered in stack or a opening bracket is encountered
        else if (isoperator(e[i]))
        {
            while (!s.empty() && !isOpenParanthesis(s.top()) && isHigherOrderOperator(s.top(), e[i]))
            {
                result += s.top();
                s.pop();
            }
            // Push the current operator in the stack
            s.push(e[i]);
        }
        else
        {
            // If operands, order of operands does not change in postfix Expression - so append it to the result.
            result += e[i];
        }
    }
    // Empty the stack at the end
    while (!s.empty() && !isOpenParanthesis(s.top()))
    {
        result += s.top();
        s.pop();
        // cout << "result=" << result << endl;
    }
    return result;
}
int main()
{
    string infixExp = "[((A+B)*C-D)*E]";
    cout << "Infix=" << infixExp << " to Postfix=" << InfixToPostfix(infixExp) << endl;
}