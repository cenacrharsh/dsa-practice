#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;
        }
        string ans = "";
        for (char ch : order)
        {
            //* if current char exists in orders string
            if (freq.find(ch) != freq.end())
            {
                for (int i = 0; i < freq[ch]; i++)
                {
                    ans += ch;
                }
                freq.erase(ch);
            }
        }
        //* add remaining characters to ans
        for (auto it : freq)
        {
            char ch = it.first;
            int num = it.second;
            for (int i = 0; i < num; i++)
            {
                ans += ch;
            }
        }
        return ans;
    }
};