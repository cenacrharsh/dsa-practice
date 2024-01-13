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
    int minSteps(string s, string t)
    {
        vector<int> freq1(26, 0), freq2(26, 0);
        for (char it : s)
        {
            freq1[it - 'a']++;
        }
        for (char it : t)
        {
            freq2[it - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] > freq2[i])
            {
                count += (freq1[i] - freq2[i]);
            }
        }
        return count;
    }
};