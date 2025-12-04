#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=ekcwMsSIzVc&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=22

//! Algorithmic Approach with Binary Search (we only get length of LIS not the actual subsequence)

/*
> Time Complexity: O(N * Log(N))
> Space Complexity: O(N)
*/

//* Using Binary Search find the index of arr[i] or find the first element greater than arr[i] -> lower_bound in c++
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
                len++;
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[index] = nums[i];
            }
        }
        return len;
    }
};

//! Algorithmic Approach

/*
> Time Complexity: O(N * N)
> Space Complexity: O(N)
*/

//- f(ind) -> the longest subseq. that ends at index ind
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
                if (nums[prev] < nums[curr] && 1 + dp[prev] > dp[curr])
                {
                    dp[curr] = 1 + dp[prev];
                }
            }
            maxLen = max(maxLen, dp[curr]);
        }
        return maxLen;
    }
};

//--------------------------------------------------------------------------------------------------------

//! Space Optimized Tabulation DP

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
        vector<int> next(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int currIndex = n - 1; currIndex >= 0; currIndex--)
        {
            //* prevIndex can't go beyond index itself so it will always start from currIndex - 1
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
            {
                //* we have to follow coordinate shift for 2nd index since in recursion we stored 2nd parameter in +1 state
                int notTake = 0 + next[prevIndex + 1];

                int take = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
                {
                    take = 1 + next[currIndex + 1];
                }

                curr[prevIndex + 1] = max(take, notTake);
            }
            next = curr;
        }

        return next[0];
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

        for (int currIndex = n - 1; currIndex >= 0; currIndex--)
        {
            //* prevIndex can't go beyond index itself so it will always start from currIndex - 1
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--)
            {
                //* we have to follow coordinate shift for 2nd index since in recursion we stored 2nd parameter in +1 state
                int notTake = 0 + dp[currIndex + 1][prevIndex + 1];

                int take = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
                {
                    take = 1 + dp[currIndex + 1][currIndex + 1];
                }

                dp[currIndex][prevIndex + 1] = max(take, notTake);
            }
        }

        return dp[0][0];
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
    int helper(vector<int> &nums, int currIndex, int prevIndex, vector<vector<int>> &dp)
    {
        if (currIndex == nums.size())
        {
            return 0;
        }

        if (dp[currIndex][prevIndex + 1] != -1)
        {
            return dp[currIndex][prevIndex + 1];
        }

        int notTake = 0 + helper(nums, currIndex + 1, prevIndex, dp);
        int take = 0;
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
        {
            take = 1 + helper(nums, currIndex + 1, currIndex, dp);
        }

        return dp[currIndex][prevIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); //* coordinate shift required to account for -1, since we can't store -1 in index, so treat -1 as 0 and so on
        return helper(nums, 0, -1, dp);
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
    int helper(vector<int> &nums, int currIndex, int prevIndex)
    {
        if (currIndex == nums.size())
        {
            return 0;
        }

        int notTake = 0 + helper(nums, currIndex + 1, prevIndex);
        int take = 0;
        if (prevIndex == -1 || nums[currIndex] > nums[prevIndex])
        {
            take = 1 + helper(nums, currIndex + 1, currIndex);
        }

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        //* f(currIndex, prevIndex) => f(0, -1): give the length of LIS starting from index 0 whose previous index is -1
        int n = nums.size();
        return helper(nums, 0, -1);
    }
};