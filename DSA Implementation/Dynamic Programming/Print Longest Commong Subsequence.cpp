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
> Time Complexity: O()
> Space Complexity: O()
*/

//! Tabulation DP -> Bottom Up Approach

/*
> Time Complexity: O()
> Space Complexity: O()
*/

class Solution
{
public:
    int lcs(string str1, string str2)
    {
        //* we will do index shift to accomodate for negative indexes in base case
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        //* printing lcs
        int len = dp[n][m];
        string ans = "";
        for (int i = 0; i < len; i++)
        {
            ans += '$';
        }

        int index = len - 1;
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans[index] = str1[i - 1];
                index--;
                i = i - 1;
                j = j - 1;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i = i - 1;
            }
            else
            {
                j = j - 1;
            }
        }
        // cout << ans << endl;

        return dp[n][m];
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