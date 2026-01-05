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
> Time Complexity: O(N * M)
> Space Complexity: O(N + M)
*/

class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                //* if characters at same position do not match we leave it and assign 0
                if (str1[i - 1] == str2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];
                    ans = max(ans, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
        }
        return ans;
    }
};

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O(N * M)
> Space Complexity: O(N * M)
*/

class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                //* if characters at same position do not match we leave it and assign 0
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

//! Memoization DP

/*
> Time Complexity: O()
> Space Complexity: O()
*/

//! Recursion -> Top Down Approach

/*
> Time Complexity: O()
> Space Complexity: O()
*/