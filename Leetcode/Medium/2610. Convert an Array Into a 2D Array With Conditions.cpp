#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

/*
> Time Complexity: O(N^2)
> Space Complexity: O(N)
*/

//! Using Unordered Map

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int maxCount = 0;
        for (auto it : nums)
        {
            m[it]++;
            maxCount = max(maxCount, m[it]);
        }
        vector<vector<int>> ans;
        while (maxCount--)
        {
            vector<int> temp;
            for (auto &it : m)
            {
                if (it.second > 0)
                {
                    temp.push_back(it.first);
                    it.second--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//*or

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> um;
        int maxCount = 0;
        for (auto it : nums)
        {
            um[it]++;
            maxCount = max(maxCount, um[it]);
        }
        vector<vector<int>> ans(maxCount);
        for (auto it : um)
        {
            int num = it.first;
            int freq = it.second;

            for (int i = 0; i < freq; i++)
            {
                ans[i].push_back(num);
            }
        }
        return ans;
    }
};