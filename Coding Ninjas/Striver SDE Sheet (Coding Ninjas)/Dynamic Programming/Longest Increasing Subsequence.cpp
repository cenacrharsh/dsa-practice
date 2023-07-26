#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);

    int maxLen = 1;
    for (int curr = 0; curr < n; curr++)
    {
        for (int prev = 0; prev < curr; prev++)
        {
            if (arr[prev] < arr[curr])
            {
                dp[curr] = max(dp[curr], 1 + dp[prev]);
            }
        }
        maxLen = max(maxLen, dp[curr]);
    }
    return maxLen;
}
