#include <iostream>
using namespace std;
string ReverseUsingStack(string s)
{
    stack<char> r;
    string reversedString;

    for (int i = 0; i < s.length(); i++)
    {
        r.push(s[i]);
    }
    while (!r.empty())
    {
        reversedString += r.top();
        r.pop();
    }
    return reversedString;
}
int main()
{
    string s = "HeLlO";
    cout << "Original String=" << s << endl;
    cout << "Reversed String=" << ReverseUsingStack(s) << endl;
}