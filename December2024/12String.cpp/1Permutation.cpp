#include <iostream>
#include <set>
using namespace std;

set<string> S;
void GetStringPermutation(int index, string &s)
{
    if (index == s.length())
    {
        S.insert(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        GetStringPermutation(index + 1, s);
        swap(s[index], s[i]); // Swap back to original string
    }
    return;
}

vector<string> findPermutation(string &s)
{
    vector<string> resultS;

    GetStringPermutation(0, s);

    for (auto rS : S)
    {
        resultS.push_back(rS);
        cout << rS << endl;
    }
    return resultS;
}

int main()
{
    string input = "ABSG";
    findPermutation(input);
}