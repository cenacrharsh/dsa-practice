#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=22

//- f(ind, lastInd) -> f(0, -1) -> give me the LIS starting from index 0 with -1 as prev index

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N)
*/

//@ f(ind) -> the longest subseq. that ends at index ind
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxLen = 1;
        for (int curr = 0; curr < n; curr++)
        {
            for (int prev = 0; prev < curr; prev++)
            {
                if (nums[prev] < nums[curr])
                {
                    dp[curr] = max(dp[curr], 1 + dp[prev]);
                }
            }
            maxLen = max(maxLen, dp[curr]);
        }
        return maxLen;
    }
};

/*
> Time Complexity: O(N * N)
> Space Complexity: O(2N)
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        //* base case, when index == n -> 0

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--)
            {
                //* +1 in 2nd parameter of dp is due to index change dp[...][index/prevIndex + 1]
                int take = INT_MIN;
                if (prevIndex == -1 || nums[index] > nums[prevIndex])
                {
                    take = 1 + next[index + 1];
                }

                int notTake = 0 + next[prevIndex + 1];

                curr[prevIndex + 1] = max(take, notTake);
            }
            next = curr;
        }

        return curr[-1 + 1];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N * N)
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        //* base case, when index == n -> 0

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--)
            {
                //* +1 in 2nd parameter of dp is due to index change dp[...][index/prevIndex + 1]
                int take = INT_MIN;
                if (prevIndex == -1 || nums[index] > nums[prevIndex])
                {
                    take = 1 + dp[index + 1][index + 1];
                }

                int notTake = 0 + dp[index + 1][prevIndex + 1];

                dp[index][prevIndex + 1] = max(take, notTake);
            }
        }

        return dp[0][-1 + 1];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N * N) + O(N) -> Recursive stack space
*/

class Solution
{
public:
    int helper(int index, int prevIndex, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return 0;
        }

        if (dp[index][prevIndex + 1] != -1)
        {
            return dp[index][prevIndex + 1];
        }

        int take = INT_MIN;
        if (prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            take = 1 + helper(index + 1, index, nums, dp);
        }

        int notTake = 0 + helper(index + 1, prevIndex, nums, dp);

        return dp[index][prevIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return helper(0, -1, nums, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N) -> Recursive stack space
*/

class Solution
{
public:
    int helper(int index, int prevIndex, vector<int> &nums)
    {
        if (index == nums.size())
        {
            return 0;
        }

        int take = INT_MIN;
        if (prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            take = 1 + helper(index + 1, index, nums);
        }

        int notTake = 0 + helper(index + 1, prevIndex, nums);

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        return helper(0, -1, nums);
    }
};