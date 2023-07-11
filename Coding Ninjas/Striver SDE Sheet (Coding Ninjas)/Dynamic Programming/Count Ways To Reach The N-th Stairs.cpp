#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <bits/stdc++.h>
int mod = 1e9 + 7;
int countDistinctWays(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int oneStep = dp[i - 1] % mod;
        int twoStep = dp[i - 2] % mod;
        dp[i] = (oneStep + twoStep) % mod;
    }
    return dp[n];
}