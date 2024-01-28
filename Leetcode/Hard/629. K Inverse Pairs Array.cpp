#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int dp[1001][1001];

    int helper(int n, int k)
    {
        if (n <= 0)
        {
            return 0;
        }
        if (k <= 0)
        {
            return k == 0;
        }

        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += helper(n - 1, k - i);
            count %= MOD;
        }

        return dp[n][k] = count;
    }
    int kInversePairs(int n, int k)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n, k);
    }
};