#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int minimizeCost(int n, int k, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minEnergySpent = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            int currEnergySpent = INT_MAX;
            if (i - j >= 0)
            {
                currEnergySpent = dp[i - j] + abs(heights[i] - heights[i - j]);
            }
            minEnergySpent = min(minEnergySpent, currEnergySpent);
        }
        dp[i] = minEnergySpent;
    }
    return dp[n - 1];
}