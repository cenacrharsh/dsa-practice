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
> Time Complexity: O(N * N)
> Space Complexity: O(N * N)
*/

class Solution
{
public:
    //* to get min insertion we'll try to keep the portion of the string that is already a pallindrome intact, for that we'll calculate longest pallindromic subseq then use (n - longest pallindromic subseq)
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
        return dp[n][m];
    }

    //* we'll use the lcs logic, since pallindrom is nothing but reverse so if a portion of the string matches in original and reversed string we can say that part in original string is pallindromic
    int longestPalinSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }

    int minInsertions(string s)
    {
        int n = s.size();
        return n - longestPalinSubseq(s);
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