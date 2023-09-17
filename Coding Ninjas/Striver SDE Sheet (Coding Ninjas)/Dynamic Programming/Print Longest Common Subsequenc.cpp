#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=-zI4mrF2Pb4

/*
> Time Complexity: O(N * M ) + O(N + M) -> to backtrack in dp array and print
> Space Complexity: O(N + M)
*/

string findLCS(int n, int m, string &s1, string &s2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // base case - fill zeroes in first rol and first col, already done in vectors

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int ansLen = dp[n][m];
    string ans = "";
    for (int i = 1; i <= ansLen; i++)
    {
        ans += '$';
    }

    int i = n, j = m, k = ansLen - 1;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans[k] = s1[i - 1];
            k--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            // go up
            i--;
        }
        else
        {
            // go left
            j--;
        }
    }

    return ans;
}