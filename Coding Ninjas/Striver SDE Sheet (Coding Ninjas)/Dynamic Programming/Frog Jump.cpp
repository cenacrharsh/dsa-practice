#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int twoStep = INT_MAX;
        if (i - 2 >= 0)
        {
            twoStep = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(oneStep, twoStep);
    }
    return dp[n - 1];
}