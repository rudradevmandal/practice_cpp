#include <iostream>
#include <map>

using namespace std;

bool isPalindrome(string s)
{
    int last = s.length() - 1;

    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[last])
        {
            return false;
        }
        last--;
    }
    return true;
}

string FindLongestPalindrome(string s)
{
    map<int, string> M;
    M.insert({1, string(1, s[0])}); // First letter is always a palindrome
    int count;
    int start = 0;
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j <= 1; j++) // j=0 - odd length, j=1 - Even length
        {
            int left = i;
            int right = i + j;

            while (left >= 0 and right < s.length() and s[left] == s[right])
            {
                int len = right - left + 1;
                if (len > maxLen)
                {
                    maxLen = len;
                    start = left;
                    M.insert({maxLen, s.substr(start, maxLen)});
                }
                left--;
                right++;
                count++;
            }
        }

        // for (int i = 2; i < s.length(); i++) // Traverse by substring length startuing from 2
        // {
        //     int j = 0;
        //     while ((j + i) <= s.length())
        //     {
        //         string substr = s.substr(j, i);
        //         cout << "i=" << i << ", j=" << j << ", substr=" << substr << ", isPalindrome=" << isPalindrome(substr) << endl;
        //         if (substr[0] == substr[-1] and isPalindrome(substr) and M.find(substr.length()) == M.end())
        //         {
        //             M.insert({substr.length(), substr});
        //         }
        //         j++;
        //         count++;
        //     }

        // for (int j = 0; j < s.length(); j++)
        // {
        //     count++;
        //     string substr = s.substr(i, j);
        //     // cout << "i=" << i << ", j=" << j << ", substr=" << substr << ", isPalindrome=" << isPalindrome(substr) << endl;
        //     if (isPalindrome(substr) and M.find(substr.length()) == M.end())
        //     {
        //         M.insert({substr.length(), substr});
        //     }
        // }
    }
    // for (auto m : M)
    //     cout << "m.first=" << m.first << ", m.second=" << m.second << endl;
    cout << "c=" << count << endl;
    return M.rbegin()->second;
}

int main()
{
    string input = "wioaackosjziuecgdgvkrvbopamrrmapobvrkvgdgceuizjsokcaaoiw";
    cout << "Longest palindrome is " << FindLongestPalindrome(input) << endl;
    cout << "Is palindrome=" << isPalindrome(input) << endl;
}