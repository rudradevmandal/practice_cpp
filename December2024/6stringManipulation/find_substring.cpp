#include <iostream>

using namespace std;

int NumberOfOccurences(string &s, string &ss)
{
    int pos = 0;
    int c = ((pos = s.find(ss)) != string::npos) ? 1 : 0;
    while ((pos = s.find(ss, pos + 1)) != string::npos)
    {
        cout << "pos " << pos << std::endl;
        c++;
    }
    return c;
}

int main()
{
    string s = "Hello World Hello Hello Hello";
    string subString = "Hello";

    cout << "Substring " << subString << " is " << ((s.find(subString) != string::npos) ? "" : "NOT ") << "present." << std::endl;

    int count = NumberOfOccurences(s, subString);
    cout << "Substring " << subString << " occurs " << count << " times." << std::endl;

    subString = 'l';
    count = NumberOfOccurences(s, subString);
    cout << "Substring " << subString << " occurs " << count << " times." << std::endl;
}