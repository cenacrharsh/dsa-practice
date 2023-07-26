#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=cKVl1TFdNXg&list=PLgUwDviBIf0pwFf-BnpkXxs0Ra0eU2sJY&index=25

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int lisLen = 1;
        for (int curr = 1; curr < n; curr++)
        {
            for (int prev = 0; prev < curr; prev++)
            {
                if (nums[prev] < nums[curr] && 1 + dp[prev] > dp[curr])
                {
                    dp[curr] = 1 + dp[prev];
                    count[curr] = count[prev]; //* inherit
                }
                else if (nums[prev] < nums[curr] && 1 + dp[prev] == dp[curr])
                {
                    count[curr] += count[prev]; //* inc the count
                }
            }
            lisLen = max(lisLen, dp[curr]);
        }

        int noOfLIS = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == lisLen)
            {
                noOfLIS += count[i];
            }
        }
        return noOfLIS;
    }
};