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
> Time Complexity: O(N * K)
> Space Complexity: O(K)
*/

class Solution
{
public:
    long long MOD = 1e9 + 7;

    int perfectSum(vector<int> &arr, int K)
    {
        //* f(n - 1, K): the number of possbile subsets of sum K from index 0->(n-1)

        int n = arr.size();
        vector<int> prev(K + 1, 0);
        vector<int> curr(K + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prev[0] = 1;
        }
        if (arr[0] <= K)
        {
            prev[arr[0]] = 1;
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 0; targetLeft <= K; targetLeft++)
            {
                int notTake = prev[targetLeft];
                int take = 0;
                if (arr[currIndex] <= targetLeft)
                {
                    take = prev[targetLeft - arr[currIndex]];
                }

                curr[targetLeft] = (notTake + take) % MOD;
            }
            prev = curr;
        }

        return prev[K];
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * K)
> Space Complexity: O(N * K)
*/

class Solution
{
public:
    long long MOD = 1e9 + 7;

    int perfectSum(vector<int> &arr, int K)
    {
        //* f(n - 1, K): the number of possbile subsets of sum K from index 0->(n-1)

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if (arr[0] <= K)
        {
            dp[0][arr[0]] = 1;
        }

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 0; targetLeft <= K; targetLeft++)
            {
                int notTake = dp[currIndex - 1][targetLeft];
                int take = 0;
                if (arr[currIndex] <= targetLeft)
                {
                    take = dp[currIndex - 1][targetLeft - arr[currIndex]];
                }

                dp[currIndex][targetLeft] = (notTake + take) % MOD;
            }
        }

        return dp[n - 1][K];
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * K)
> Space Complexity: O(N * K) + O(N)
*/

class Solution
{
public:
    long long MOD = 1e9 + 7;
    int helper(vector<int> &arr, int currIndex, int targetLeft, vector<vector<int>> &dp)
    {
        if (targetLeft == 0)
        {
            return 1;
        }

        if (currIndex == 0)
        {
            return (arr[0] == targetLeft) ? 1 : 0;
        }

        if (dp[currIndex][targetLeft] != -1)
        {
            return dp[currIndex][targetLeft];
        }

        int notTake = helper(arr, currIndex - 1, targetLeft, dp);
        int take = 0;
        if (arr[currIndex] <= targetLeft)
        {
            take = helper(arr, currIndex - 1, targetLeft - arr[currIndex], dp);
        }

        return dp[currIndex][targetLeft] = (notTake + take) % MOD;
    }

    int perfectSum(vector<int> &arr, int K)
    {
        //* f(n - 1, K): the number of possbile subsets of sum K from index 0->(n-1)
        vector<vector<int>> dp(arr.size(), vector<int>(K + 1, -1));
        return helper(arr, arr.size() - 1, K, dp);
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
    int helper(vector<int> &arr, int currIndex, int targetLeft)
    {
        if (targetLeft == 0)
        {
            return 1;
        }

        if (currIndex == 0)
        {
            return arr[0] == targetLeft;
        }

        int notTake = helper(arr, currIndex - 1, targetLeft);
        int take = 0;
        if (arr[currIndex] <= targetLeft)
        {
            take = helper(arr, currIndex - 1, targetLeft - arr[currIndex]);
        }

        return notTake + take;
    }

    int perfectSum(vector<int> &arr, int K)
    {
        //* f(n - 1, K): the number of possbile subsets of sum K from index 0->(n-1)
        return helper(arr, arr.size() - 1, K);
    }
};