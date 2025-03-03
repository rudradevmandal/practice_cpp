#include <iostream>
#include <map>
using namespace std;

string ReverseString(string i)
{
    stack<string> S;
    string word;
    for (auto c : i)
    {
        if (c != ' ')
        {
            word = word + c;
        }
        else
        {
            if (!word.empty())
            {
                S.push(word);
                word = "";
            }
        }
    }
    string result;
    if (!S.empty())
        result = S.top();
    else
        return "";
    S.pop();
    while (!S.empty())
    {
        result = result + " " + S.top();
        S.pop();
    }
    return result;
}

string CountRepeats(string i)
{
    map<char, int> M;
    int count;
    for (char c : i)
    {
        M[c]++;
    }
    string result;
    for (auto it : M)
    {
        result += it.first + to_string(it.second);
    }
    return result;
}

int main()
{
    string input = "Hello World  Universe            Galaxy ";
    cout << "Reversed string is " << ReverseString(input) << endl;

    // Count substrings
    input = "aaaaabbbccdddd";
    cout << "Repeated string is " << CountRepeats(input) << endl;
}