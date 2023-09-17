#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=xElxAuBcvsU&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=15

//- length of smallest supersequence = n + m - LCS(n, m), because between the 2 stirngs the common part in taken only once so to minimize the supersequence length we maximize the comman part hence LCS of the 2 strings

//- if characters match we move to diagonal element in the dp table and include the common element once, if not equal we move to the up/left whichever is greater and the char which gets left behind is the one we add to our ans, eg. if we move up we leave the curr rows element so we add it to our ans

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        //* LCS Part
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
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
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // up
                ans += str1[i - 1];
                i--;
            }
            else
            {
                // left
                ans += str2[j - 1];
                j--;
            }
        }
        while (i > 0)
        {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += str2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};