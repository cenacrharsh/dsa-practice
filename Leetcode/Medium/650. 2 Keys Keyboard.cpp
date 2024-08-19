#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Memoization

class Solution
{
public:
    int helper(int n, int count, int clipboard, vector<vector<int>> &dp)
    {
        if (count == n)
        {
            return 0;
        }

        if (count > n)
        {
            return 1e9;
        }

        if (dp[count][clipboard] != -1)
        {
            return dp[count][clipboard];
        }

        //* Paste
        int paste = 1 + helper(n, count + clipboard, clipboard, dp);

        //* Copy and Paste
        int copyAndPaste = 2 + helper(n, count * 2, count, dp);

        return dp[count][clipboard] = min(paste, copyAndPaste);
    }

    int minSteps(int n)
    {
        if (n == 1)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int minSteps = 1 + helper(n, 1, 1, dp);
        return minSteps;
    }
};

//! Recursion

class Solution
{
public:
    int helper(int n, int count, int clipboard)
    {
        if (count == n)
        {
            return 0;
        }

        if (count > n)
        {
            return 1e9;
        }

        //* Paste
        int paste = 1 + helper(n, count + clipboard, clipboard);

        //* Copy and Paste
        int copyAndPaste = 2 + helper(n, count * 2, count);

        return min(paste, copyAndPaste);
    }

    int minSteps(int n)
    {
        if (n == 1)
        {
            return 0;
        }

        int minSteps = 1 + helper(n, 1, 1);
        return minSteps;
    }
};