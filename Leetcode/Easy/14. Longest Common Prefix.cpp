#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! With Trie

//TODO

//! Without Trie

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string ans = "";
        string firstWord = strs[0];
        string lastWord = strs[strs.size() - 1];
        int len = min(firstWord.size(), lastWord.size());
        for (int i = 0; i < len; i++)
        {
            if (firstWord[i] == lastWord[i])
            {
                ans += firstWord[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};