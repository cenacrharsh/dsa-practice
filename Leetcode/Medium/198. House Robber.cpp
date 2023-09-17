#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=3WaxQMELSkw

//! Space Optimized Tabulation DP
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int rob = nums[i];
            if (i > 1)
            {
                rob += prev2;
            }
            int notRob = 0 + prev;
            int curr = max(rob, notRob);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

//! Tabulation DP -> Bottom Up Approach
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        if (nums.size() > 1)
        {
            dp[1] = max(nums[0], nums[1]);
        }
        for (int i = 2; i < nums.size(); i++)
        {
            int rob = nums[i] + dp[i - 2];
            int notRob = dp[i - 1];
            dp[i] = max(rob, notRob);
        }
        return dp[nums.size() - 1];
    }
};

//! Memoization DP
class Solution
{
public:
    int helper(vector<int> &nums, int houseNumber, vector<int> &dp)
    {
        if (houseNumber < 0)
        {
            return 0;
        }

        if (houseNumber == 0)
        {
            return nums[houseNumber];
        }

        if (dp[houseNumber] != -1)
        {
            return dp[houseNumber];
        }

        int rob = nums[houseNumber] + helper(nums, houseNumber - 2, dp);
        int notRob = helper(nums, houseNumber - 1, dp);

        return dp[houseNumber] = max(rob, notRob);
    }
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return helper(nums, nums.size() - 1, dp);
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    int helper(vector<int> &nums, int houseNumber)
    {
        if (houseNumber < 0)
        {
            return 0;
        }

        if (houseNumber == 0)
        {
            return nums[houseNumber];
        }

        int rob = nums[houseNumber] + helper(nums, houseNumber - 2);
        int notRob = helper(nums, houseNumber - 1);

        return max(rob, notRob);
    }

    int rob(vector<int> &nums)
    {
        return helper(nums, nums.size() - 1);
    }
};
