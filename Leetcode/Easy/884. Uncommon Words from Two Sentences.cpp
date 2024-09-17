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
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        unordered_map<string, int> freq;
        string word = "";
        s1 += " ";
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != ' ')
            {
                word += s1[i];
            }
            else
            {
                freq[word]++;
                word = "";
            }
        }
        word = "";
        s2 += " ";
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] != ' ')
            {
                word += s2[i];
            }
            else
            {
                freq[word]++;
                word = "";
            }
        }
        vector<string> ans;
        for (auto it : freq)
        {
            if (it.second == 1)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};