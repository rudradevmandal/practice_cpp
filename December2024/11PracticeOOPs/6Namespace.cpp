#include <iostream>
using namespace std;

namespace N1
{
    void Print() { cout << "I am in N1." << endl; }
}

namespace N2
{
    void Print() { cout << "I am in N2." << endl; }
}

using namespace N1;
int main()
{
    Print();
}