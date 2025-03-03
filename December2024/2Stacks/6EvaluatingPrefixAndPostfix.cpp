#include <iostream>
using namespace std;
int EvaluateOperator(int a, int b, char o)
{
    if (o == '+')
        return a + b;
    else if (o == '-')
        return a - b;
    else if (o == '*')
        return a * b;
    else if (o == '/')
        return a / b;
    cout << "Error: Wrong operator provided." << endl;
    return 0;
}
int EvaluatePostfixExp(string e)
{
    stack<int> s;
    int result = 0;
    char operators[4] = {'+', '-', '*', '/'};

    for (int i = 0; i < e.length(); i++)
    {
        if (e[i] != operators[0] && e[i] != operators[1] && e[i] != operators[2] && e[i] != operators[3])
        {
            s.push((e[i] - '0'));
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (e[i] == operators[j])
                {
                    if (s.empty())
                    {
                        cout << "Error: Wrong postfix expression." << endl;
                        return 0;
                    }
                    int b = s.top();
                    s.pop();
                    if (s.empty())
                    {
                        cout << "Error: Wrong postfix expression." << endl;
                        return 0;
                    }
                    int a = s.top();
                    s.pop();
                    result = EvaluateOperator(a, b, e[i]);
                    s.push(result);
                }
            }
        }
    }
    return s.top();
}
int EvaluatePrefixExp(string e)
{
    stack<int> s;
    int result = 0;
    char operators[4] = {'+', '-', '*', '/'};

    for (int i = e.length(); i >= 0; i--)
    {
        if (e[i] != operators[0] && e[i] != operators[1] && e[i] != operators[2] && e[i] != operators[3])
        {
            s.push((e[i] - '0'));
        }
        else
        {
            for (int j = 0; j < 4; j++)
            {
                if (e[i] == operators[j])
                {
                    if (s.empty())
                    {
                        cout << "Error: Wrong postfix expression." << endl;
                        return 0;
                    }
                    int a = s.top();
                    s.pop();
                    if (s.empty())
                    {
                        cout << "Error: Wrong postfix expression." << endl;
                        return 0;
                    }
                    int b = s.top();
                    s.pop();
                    result = EvaluateOperator(a, b, e[i]);
                    s.push(result);
                }
            }
        }
    }
    return s.top();
}
int main()
{
    string postfixExp = "32*54*+9-";
    string prefixExp = "-+*32*549";
    cout << "Evaluation of Postfix expression=" << postfixExp << " is " << EvaluatePostfixExp(postfixExp) << endl;
    cout << "Evaluation of Prefix expression=" << prefixExp << " is " << EvaluatePrefixExp(prefixExp) << endl;
}