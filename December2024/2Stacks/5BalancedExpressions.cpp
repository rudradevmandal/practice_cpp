#include <iostream>
using namespace std;

bool isBalanced(string e)
{
    char open[3] = {'(', '[', '{'};
    char close[3] = {')', ']', '}'};
    stack<char> s;

    for (int i = 0; i < e.length(); i++)
    {
        // Push only opening braces expressions
        if (e[i] == open[0] || e[i] == open[1] || e[i] == open[2])
        {
            s.push(e[i]);
            continue;
        }
        for (int j = 0; j < 3; j++)
        {
            // Check if the closing brace expression corresponds to the last open brace expression
            if (e[i] == close[j])
            {
                if (s.empty() || s.top() != open[j])
                    return false;
                s.pop();
            }
        }
    }
    return s.empty() ? true : false;
}
int main()
{
    string expression = "[{()}]";
    cout << "isBalanced=" << (isBalanced(expression) ? "true" : "false") << endl;
}