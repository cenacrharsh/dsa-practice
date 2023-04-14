#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

//! Tabulation DP -> Bottom Up Approach
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[n - 1] = 1;
        int lastIndex = n - 1;
        for (int currIndex = n - 1; currIndex >= 0; currIndex--)
        {
            if (currIndex + nums[currIndex] >= lastIndex)
            {
                dp[currIndex] = 1;
                lastIndex = currIndex;
            }
        }
        return (dp[0] == 1 ? true : false);
    }
};

//! Memoization DP
class Solution
{
public:
    bool helper(vector<int> &nums, int index, vector<int> &dp)
    {
        if (index >= nums.size() - 1)
        {
            return true;
        }

        if (dp[index] != -1)
        {
            return dp[index];
        }

        bool ans = false;
        for (int i = 1; i <= nums[index]; i++)
        {
            ans = ans || helper(nums, index + i, dp);
        }
        return dp[index] = ans;
    }
    bool canJump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    bool helper(vector<int> &nums, int index)
    {
        if (index >= nums.size() - 1)
        {
            return true;
        }
        bool ans = false;
        for (int i = 1; i <= nums[index]; i++)
        {
            ans = ans || helper(nums, index + i);
        }
        return ans;
    }
    bool canJump(vector<int> &nums)
    {
        return helper(nums, 0);
    }
};