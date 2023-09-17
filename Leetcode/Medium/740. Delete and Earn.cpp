#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

//! Tabulation DP -> Bottom Up Approach (Using House Robber Approach)
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        // 10^4 = 10,000
        vector<int> sum(10001, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            sum[nums[i]] += nums[i];
        }

        vector<int> dp(10001, 0);
        dp[1] = sum[1];
        dp[2] = max(sum[1], sum[2]);
        for (int i = 3; i < dp.size(); i++)
        {
            int pick = sum[i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[10000];
    }
};

//! Memoization DP
class Solution
{
public:
    int helper(vector<int> &nums, int currIndex, vector<int> &dp)
    {
        if (currIndex < 0)
        {
            return 0;
        }

        if (dp[currIndex] != -1)
        {
            return dp[currIndex];
        }

        int currValue = nums[currIndex];
        int currSum = nums[currIndex];
        int index = currIndex + 1;

        // add all elements with value same as currValue, because say we have 2 4's, if we take one 4 then we have to get rid of 3 and 5, but since we already got rid of 3 and 5 it's better to count all 4's to maximize our sum
        while (index >= 0 && nums[index] == currValue)
        {
            currSum += nums[index];
            index--;
        }

        // due to sorting we already know we don't have to check for currValue + 1, we just skip all currValue - 1 elements
        while (index >= 0 && nums[index] == currValue - 1)
        {
            index--;
        }

        // now we either pick the currElement or we don't, if we pick it, we pass index which already has skipped any duplicates and currValue - 1 elements if any, if we don't pick it up then we simply pass currIndex - 1
        return dp[currIndex] = max(currSum + helper(nums, index, dp), helper(nums, currIndex - 1, dp));
    }

    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), -1);
        return helper(nums, nums.size() - 1, dp); // starting from last index
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    int helper(vector<int> &nums, int currIndex)
    {
        if (currIndex < 0)
        {
            return 0;
        }

        int currValue = nums[currIndex];
        int currSum = nums[currIndex];
        int index = currIndex + 1;

        // add all elements with value same as currValue, because say we have 2 4's, if we take one 4 then we have to get rid of 3 and 5, but since we already got rid of 3 and 5 it's better to count all 4's to maximize our sum
        while (index >= 0 && nums[index] == currValue)
        {
            currSum += nums[index];
            index--;
        }

        // due to sorting we already know we don't have to check for currValue + 1, we just skip all currValue - 1 elements
        while (index >= 0 && nums[index] == currValue - 1)
        {
            index--;
        }

        // now we either pick the currElement or we don't, if we pick it, we pass index which already has skipped any duplicates and currValue - 1 elements if any, if we don't pick it up then we simply pass currIndex - 1
        return max(currSum + helper(nums, index), helper(nums, currIndex - 1));
    }

    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return helper(nums, nums.size() - 1); // starting from last index
    }
};