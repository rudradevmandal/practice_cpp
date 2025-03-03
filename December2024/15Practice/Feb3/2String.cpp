#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

string ReverseChar(string s)
{
    string result = s;
    int left = 0;
    int right = s.length() - 1;
    while (left < right)
    {
        swap(result[left++], result[right--]);
    }
    return result;
}

string ReverseString(string s)
{
    string result = "";
    string word = "";
    int i = 0;
    int length = s.length();
    while (i < length)
    {
        word += s[i];
        if (s[i] == ' ' or i == length - 1)
        {
            if (word != " ")
                result = word + " " + result;
            word = "";
        }
        i++;
    }
    return result;
}

int main()
{
    string input = "Hello     World";

    cout << "ReverseChar=" << ReverseChar(input) << endl;
    cout << "ReverseChar=" << ReverseString(input) << endl;
}