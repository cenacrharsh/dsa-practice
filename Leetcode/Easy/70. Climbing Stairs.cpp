#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=4

//> Ques is same as fibonaci number as recurrence relation is same, only initial values differ

//! Space Optimized DP
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        int prev = 1;
        int secondPrev = 1;

        for (int i = 2; i <= n; i++)
        {
            int curr = prev + secondPrev;
            secondPrev = prev;
            prev = curr;
        }

        return prev;
    }
};

//! Tabulation - Bottom Up Approach
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int oneStep = dp[i - 1];
            int twoStep = dp[i - 2];
            dp[i] = oneStep + twoStep;
        }

        return dp[n];
    }
};

//! Memoization
class Solution
{
public:
    int helper(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }

        if (dp[n] != -1)
        {
            return dp[n];
        }
        else
        {
            // climb down one step
            int oneStep = helper(n - 1, dp);

            // climb down two steps
            int twoStep = helper(n - 2, dp);

            return dp[n] = oneStep + twoStep;
        }
    }
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};

//! Recursion - Top Down Approach
class Solution
{
public:
    int helper(int n)
    {
        //* we are treating 0 as the goal, so if already there you can't do anything or if at 1 to go at 0 we only have one option
        if (n == 0 || n == 1)
        {
            return 1;
        }

        // climb down one step
        int oneStep = helper(n - 1);

        // climb down two steps
        int twoStep = helper(n - 2);

        return oneStep + twoStep;
    }

    int climbStairs(int n)
    {
        return helper(n);
    }
};