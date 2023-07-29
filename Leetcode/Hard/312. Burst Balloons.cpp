#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=Yz4LlDSlkns&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=26

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * N) + O(N)
> Space Complexity: O(N  * N)
*/

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i > j)
                {
                    continue; //* base case
                }

                int maxCoins = INT_MIN;
                for (int index = i; index <= j; index++)
                {
                    int currCoins = (nums[i - 1] * nums[index] * nums[j + 1]) +
                                    dp[i][index - 1] + dp[index + 1][j];
                    maxCoins = max(maxCoins, currCoins);
                }
                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * N) + O(N)
> Space Complexity: O(N * N) + O(N)
*/

class Solution
{
public:
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int maxCoins = INT_MIN;
        for (int index = i; index <= j; index++)
        {
            int currCoins = (nums[i - 1] * nums[index] * nums[j + 1]) +
                            helper(i, index - 1, nums, dp) + helper(index + 1, j, nums, dp);
            maxCoins = max(maxCoins, currCoins);
        }

        return dp[i][j] = maxCoins;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return helper(1, n, nums, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: Exponential
> Space Complexity: O(N)
*/

class Solution
{
public:
    int helper(int i, int j, vector<int> &nums)
    {
        if (i > j)
        {
            return 0;
        }

        int maxCoins = INT_MIN;
        for (int index = i; index <= j; index++)
        {
            int currCoins = (nums[i - 1] * nums[index] * nums[j + 1]) +
                            helper(i, index - 1, nums) + helper(index + 1, j, nums);
            maxCoins = max(maxCoins, currCoins);
        }

        return maxCoins;
    }

    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return helper(1, n, nums); //* 0, 1, 2, 3...n - 1, n -> now n is actually n + 2 so index goes from 0 -> n - 1, hence to send index of 2nd last element we send n
    }
};