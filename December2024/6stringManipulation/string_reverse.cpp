#include <iostream>

using namespace std;

string ReverseUsingStack(string &s)
{
    stack<char> st;
    string rs;
    for (char c : s)
        st.push(c);

    while (!st.empty())
    {
        rs.push_back(st.top());
        st.pop();
    }
    return rs;
}

void ReverseUsingSwap(string &s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

void ReverseUsingRecursion(string &s, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(s[start], s[end]);
    ReverseUsingRecursion(s, start + 1, end - 1);
}

int main()
{
    string input;
    cout << "Enter a string: " << std::endl;
    cin >> input;

    cout << "Original String: " << input << std::endl;

    cout << "Reverse using std::reverse()" << std::endl;
    reverse(input.begin(), input.end());
    cout << "Reversed String: " << input << std::endl;

    cout << "Reverse using string constructor" << std::endl;
    input = string(input.rbegin(), input.rend());
    cout << "Reversed String: " << input << std::endl;

    cout << "Reverse using stack" << std::endl;
    input = ReverseUsingStack(input);
    cout << "Reversed String: " << input << std::endl;

    cout << "Reverse using std::swap()" << std::endl;
    ReverseUsingSwap(input);
    cout << "Reversed String: " << input << std::endl;

    cout << "Reverse using recursion" << std::endl;
    ReverseUsingRecursion(input, 0, input.length() - 1);
    cout << "Reversed String: " << input << std::endl;
}