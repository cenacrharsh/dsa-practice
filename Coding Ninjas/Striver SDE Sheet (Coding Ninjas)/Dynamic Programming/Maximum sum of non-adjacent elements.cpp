#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    for (int i = 0; i < n; i++)
    {
        // include the element
        int take = nums[i];
        if (i - 2 >= 0)
        {
            take += dp[i - 2];
        }

        // don't include the element
        int notTake = 0 + dp[i - 1];

        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}