#include <iostream>

using namespace std;

vector<int> FindDuplicates(vector<int> d)
{
    vector<int> dup;
    sort(d.begin(), d.end());
    for (int i = 0; i < d.size() - 1; i++)
    {
        if (d.at(i) == d.at(i + 1))
            dup.push_back(d.at(i));
    }
    return dup;
}

vector<int> FindDuplicatesMap(vector<int> d)
{
    unordered_map<int, int> freq;
    vector<int> dup;
    for (auto i : d)
        freq[i]++;
    for (auto entry : freq)
    {
        if (entry.second > 1)
        {
            dup.push_back(entry.first);
        }
    }
    return dup;
}
int main()
{
    vector<int> A = {2, 5, 1, 2, 5, 0, 6, 4};
    vector<int> dup = FindDuplicates(A);
    vector<int> dupMap = FindDuplicatesMap(A);

    for (auto d : dup)
        cout << "Repeating numbers: " << d << endl;
    for (auto d : dupMap)
        cout << "Repeating MAP numbers: " << d << endl;

    return 0;
}