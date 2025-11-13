#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP

/*
> Time Complexity: O(N * target)
> Space Complexity: O(target)
*/

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int target)
    {
        //* f(n - 1, target): if a subset exist with sum target from index 0->(n - 1)
        int n = arr.size();
        vector<bool> prev(target + 1, false); //* target goes from 0->target so target + 1 indexes
        vector<bool> curr(target + 1, false);

        prev[0] = true;
        curr[0] = true;

        prev[arr[0]] = true; //* for currIndex = 0, we set it as true, that too only if arr[0] == target

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 1; targetLeft <= target; targetLeft++)
            {
                bool take = false;
                if (targetLeft >= arr[currIndex])
                {
                    take = prev[targetLeft - arr[currIndex]];
                }
                bool notTake = prev[targetLeft];

                curr[targetLeft] = take || notTake;
            }
            prev = curr;
        }

        return prev[target];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * target)
> Space Complexity: O(N * target)
*/

class Solution
{
public:
    bool isSubsetSum(vector<int> arr, int target)
    {
        //* f(n - 1, target): if a subset exist with sum target from index 0->(n - 1)
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false)); //* target goes from 0->target so target + 1 indexes

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        dp[0][arr[0]] = true; //* for currIndex = 0, we set it as true, that too only if arr[0] == target

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 1; targetLeft <= target; targetLeft++)
            {
                bool take = false;
                if (targetLeft >= arr[currIndex])
                {
                    take = dp[currIndex - 1][targetLeft - arr[currIndex]];
                }
                bool notTake = dp[currIndex - 1][targetLeft];

                dp[currIndex][targetLeft] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * target)
> Space Complexity: O(N * target) + O(N)
*/

class Solution
{
public:
    bool helper(vector<int> &arr, int targetLeft, int currIndex, vector<vector<int>> &dp)
    {
        //* for base case: f(0, target): only possible to achieve target if arr[0] == target
        if (targetLeft == 0)
        {
            return true;
        }
        if (currIndex == 0)
        {
            return arr[0] == targetLeft;
        }

        if (dp[currIndex][targetLeft] != -1)
        {
            return dp[currIndex][targetLeft];
        }

        bool take = false;
        if (targetLeft >= arr[currIndex])
        {
            take = helper(arr, targetLeft - arr[currIndex], currIndex - 1, dp);
        }
        bool notTake = helper(arr, targetLeft, currIndex - 1, dp);

        return dp[currIndex][targetLeft] = take || notTake;
    }

    bool isSubsetSum(vector<int> arr, int target)
    {
        //* f(n - 1, target): if a subset exist with sum target from index 0->(n - 1)
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); //* target goes from 0->target so target + 1 indexes
        return helper(arr, target, arr.size() - 1, dp);
    }
};

//! Recursion -> Top Down Approach

/*
> Time Complexity: O(2^N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    bool helper(vector<int> &arr, int target, int currIndex)
    {
        //* for base case: f(0, target): only possible to achieve target if arr[0] == target
        if (target == 0)
        {
            return true;
        }
        if (currIndex == 0)
        {
            return arr[0] == target;
        }

        bool take = false;
        if (target >= arr[currIndex])
        {
            take = helper(arr, target - arr[currIndex], currIndex - 1);
        }
        bool notTake = helper(arr, target, currIndex - 1);

        return take || notTake;
    }

    bool isSubsetSum(vector<int> arr, int target)
    {
        //* f(n - 1, target): if a subset exist with sum target from index 0->(n - 1)
        return helper(arr, target, arr.size() - 1);
    }
};