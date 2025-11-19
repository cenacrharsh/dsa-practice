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
> Time Complexity: O(N * Target)
> Space Complexity: O(Target)
*/

class Solution
{
public:
    long long MOD = 1e9 + 7;
    int countSubsetsWithSumK(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);

        if (arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 0; targetLeft <= target; targetLeft++)
            {
                int notTake = prev[targetLeft];
                int take = 0;
                if (arr[currIndex] <= targetLeft)
                {
                    take = prev[targetLeft - arr[currIndex]];
                }

                curr[targetLeft] = (take + notTake) % MOD;
            }
            prev = curr;
        }

        return prev[target];
    }

    int countPartitions(int n, int diff, vector<int> &arr)
    {
        /*
            s1 + s2 = totalSum => s1 = totalSum - s2
            s1 - s2 = diff => totalSum - s2 - s2 = diff => s2 = (totalSum - diff) / 2
            so we are looking for subsets with sum = (totalSum - diff) / 2
            edge cases: (totalSum - diff) has to be > 0 since there are no -ve numbers so negative not possible, (totalSum - diff) must be even since after 2 we don't want any decimals since there are no fractions so subset sum can't be a fraction
        */

        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        if ((totalSum - diff) < 0 || (totalSum - diff) % 2 != 0)
        {
            return false;
        }

        int target = (totalSum - diff) / 2;
        return countSubsetsWithSumK(arr, target);
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * Target)
> Space Complexity: O(N * Target)
*/

class Solution
{
public:
    long long MOD = 1e9 + 7;
    int countSubsetsWithSumK(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        if (arr[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int currIndex = 1; currIndex < n; currIndex++)
        {
            for (int targetLeft = 0; targetLeft <= target; targetLeft++)
            {
                int notTake = dp[currIndex - 1][targetLeft];
                int take = 0;
                if (arr[currIndex] <= targetLeft)
                {
                    take = dp[currIndex - 1][targetLeft - arr[currIndex]];
                }

                dp[currIndex][targetLeft] = (take + notTake) % MOD;
            }
        }

        return dp[n - 1][target];
    }

    int countPartitions(int n, int diff, vector<int> &arr)
    {
        /*
            s1 + s2 = totalSum => s1 = totalSum - s2
            s1 - s2 = diff => totalSum - s2 - s2 = diff => s2 = (totalSum - diff) / 2
            so we are looking for subsets with sum = (totalSum - diff) / 2
            edge cases: (totalSum - diff) has to be > 0 since there are no -ve numbers so negative not possible, (totalSum - diff) must be even since after 2 we don't want any decimals since there are no fractions so subset sum can't be a fraction
        */

        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        if ((totalSum - diff) < 0 || (totalSum - diff) % 2 != 0)
        {
            return false;
        }

        int target = (totalSum - diff) / 2;
        return countSubsetsWithSumK(arr, target);
    }
};

//! Memoization DP

/*
> Time Complexity: O(N * Target)
> Space Complexity: O(N * Target) + O(N)
*/

class Solution
{
public:
    long long MOD = 1e9 + 7;
    int helper(vector<int> &arr, int currIndex, int targetLeft, vector<vector<int>> &dp)
    {
        /*
            here arr[i] = 0 is also possible so original base cases won't work, we can't return as soon as get targetLeft == 0, we have to go deep till the last index to explore all cases
        */

        if (currIndex == 0)
        {
            if (targetLeft == 0 && arr[0] == 0)
                return 2; //* if target has become 0 and last element itself is 0, we have 2 options pick/notPick both are valid
            if (targetLeft == 0 || targetLeft == arr[0])
                return 1; //* since target is already 0 we only have notPick, or if targetLeft == arr[0] we only have pick option
            return 0;
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

        return dp[currIndex][targetLeft] = (take + notTake) % MOD;
    }

    int countSubsetsWithSumK(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(arr, n - 1, target, dp);
    }

    int countPartitions(int n, int diff, vector<int> &arr)
    {
        /*
            s1 + s2 = totalSum => s1 = totalSum - s2
            s1 - s2 = diff => totalSum - s2 - s2 = diff => s2 = (totalSum - diff) / 2
            so we are looking for subsets with sum = (totalSum - diff) / 2
            edge cases: (totalSum - diff) has to be > 0 since there are no -ve numbers so negative not possible, (totalSum - diff) must be even since after 2 we don't want any decimals since there are no fractions so subset sum can't be a fraction
        */

        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        if ((totalSum - diff) < 0 || (totalSum - diff) % 2 != 0)
        {
            return false;
        }

        int target = (totalSum - diff) / 2;
        return countSubsetsWithSumK(arr, target);
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
        /*
            here arr[i] = 0 is also possible so original base cases won't work, we can't return as soon as get targetLeft == 0, we have to go deep till the last index to explore all cases
        */

        if (currIndex == 0)
        {
            if (targetLeft == 0 && arr[0] == 0)
                return 2; //* if target has become 0 and last element itself is 0, we have 2 options pick/notPick both are valid
            if (targetLeft == 0 || targetLeft == arr[0])
                return 1; //* since target is already 0 we only have notPick, or if targetLeft == arr[0] we only have pick option
            return 0;
        }

        int notTake = helper(arr, currIndex - 1, targetLeft);
        int take = 0;
        if (arr[currIndex] <= targetLeft)
        {
            take = helper(arr, currIndex - 1, targetLeft - arr[currIndex]);
        }

        return take + notTake;
    }

    int countSubsetsWithSumK(vector<int> &arr, int target)
    {
        int n = arr.size();
        return helper(arr, n - 1, target);
    }

    int countPartitions(int n, int diff, vector<int> &arr)
    {
        /*
            s1 + s2 = totalSum => s1 = totalSum - s2
            s1 - s2 = diff => totalSum - s2 - s2 = diff => s2 = (totalSum - diff) / 2
            so we are looking for subsets with sum = (totalSum - diff) / 2
            edge cases: (totalSum - diff) has to be > 0 since there are no -ve numbers so negative not possible, (totalSum - diff) must be even since after 2 we don't want any decimals since there are no fractions so subset sum can't be a fraction
        */

        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            totalSum += arr[i];
        }

        if ((totalSum - diff) < 0 || (totalSum - diff) % 2 != 0)
        {
            return false;
        }

        int target = (totalSum - diff) / 2;
        return countSubsetsWithSumK(arr, target);
    }
};