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
    int maxFrequencyElements(vector<int> &nums)
    {
        map<int, int> um;
        int maxFreq = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            um[nums[i]]++;
            maxFreq = max(maxFreq, um[nums[i]]);
        }
        int ans = 0;
        for (auto it : um)
        {
            int freq = it.second;
            if (freq == maxFreq)
            {
                ans += freq;
            }
        }
        return ans;
    }
};