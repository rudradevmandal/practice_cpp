#include <iostream>
using namespace std;

int Add(int a, int b)
{
    return a + b;
}

string Add(char a, char b)
{
    string result;
    return result + a + b;
}

int main()
{
    cout << "Add integers 1 and 2 is " << Add(1, 2) << endl;
    cout << "Add char a and b is " << Add('a', 'b') << endl;
}