#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
    int nonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += prev2;
            }
            int notPick = prev;
            prev2 = prev;
            prev = max(pick, notPick);
        }
        return prev;
    }
};

//! Tabulation DP -> Bottom Up Approach
class Solution
{
public:
    int nonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};

//! Memoization DP
class Solution
{
public:
    //* f(n - 1): max sum of non-adjacent numbers from 0->(n-1)
    int helper(vector<int> &nums, int currentIndex, vector<int> &dp)
    {
        // if (currentIndex < 0)
        // {
        //     return 0;
        // }

        if (dp[currentIndex] != -1)
        {
            return dp[currentIndex];
        }

        if (currentIndex == 0)
        {
            return nums[currentIndex]; //* reaching index 0 indicates we must have skipped index 1 so we can simply pick value of index 0
        }

        int pick = nums[currentIndex];
        if (currentIndex > 1)
        {
            pick += helper(nums, currentIndex - 2, dp);
        }
        int notPick = helper(nums, currentIndex - 1, dp);

        return dp[currentIndex] = max(pick, notPick);
    }

    int nonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(nums.size(), -1);
        return helper(nums, n - 1, dp);
    }
};

//! Recursion -> Top Down Approach
class Solution
{
public:
    //* f(n - 1): max sum of non-adjacent numbers from 0->(n-1)
    int helper(vector<int> &nums, int currentIndex)
    {
        // if (currentIndex < 0)
        // {
        //     return 0;
        // }

        if (currentIndex == 0)
        {
            return nums[currentIndex]; //* reaching index 0 indicates we must have skipped index 1 so we can simply pick value of index 0
        }

        int pick = nums[currentIndex];
        if (currentIndex > 1)
        {
            pick += helper(nums, currentIndex - 2);
        }
        int notPick = helper(nums, currentIndex - 1);

        return max(pick, notPick);
    }

    int nonAdjacent(vector<int> &nums)
    {
        int n = nums.size();
        return helper(nums, n - 1);
    }
};
