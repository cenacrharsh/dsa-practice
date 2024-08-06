#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Freq Array

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.size(); i++)
        {
            freq[word[i] - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            cout << i << " " << freq[i] << endl;
            int push = (i / 8) + 1; //* gives 1 for i = 0 -> 7, 2 for i = 8 -> 15, 3 for i = 16 -> 23, 4 for i = 24 -> 25
            ans += freq[i] * push;
        }
        return ans;
    }
};