#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation

/*
> Time Complexity: O(K * N)
> Space Complexity: O(K) -> Min we need k prev values
*/

//! Tabulation

/*
> Time Complexity: O(K * N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for (int j = 1; j < n; j++)
        {
            int minStep = INT_MAX;
            for (int i = 1; i <= k; i++)
            {
                if (j - i >= 0)
                {
                    int kthStep = dp[j - i] + abs(heights[j] - heights[j - i]);
                    minStep = min(minStep, kthStep);
                }
            }
            dp[j] = minStep;
        }
        return dp[n - 1];
    }
};

//! Memoization

/*
> Time Complexity: O(K * N)
> Space Complexity: O(N) + O(N)
*/

class Solution
{
public:
    int helper(vector<int> &heights, int k, int currStep, vector<int> &dp)
    {
        if (currStep == 0)
        {
            return 0;
        }

        if (dp[currStep] != -1)
        {
            return dp[currStep];
        }

        int minStep = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (currStep - i >= 0)
            {
                int kthStep = helper(heights, k, currStep - i, dp) + abs(heights[currStep] - heights[currStep - i]);
                minStep = min(minStep, kthStep);
            }
        }

        return dp[currStep] = minStep;
    }

    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, -1);
        return helper(heights, k, n - 1, dp);
    }
};

//! Recursion

/*
> Time Complexity: O(2^K)
> Space Complexity: O(N) + O(N)

*/
class Solution
{
public:
    int helper(vector<int> &heights, int k, int currStep)
    {
        if (currStep == 0)
        {
            return 0;
        }

        int minStep = INT_MAX;
        for (int i = 1; i <= k; i++)
        {
            if (currStep - i >= 0)
            {
                int kthStep = helper(heights, k, currStep - i) + abs(heights[currStep] - heights[currStep - i]);
                minStep = min(minStep, kthStep);
            }
        }

        return minStep;
    }

    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        return helper(heights, k, n - 1);
    }
};
