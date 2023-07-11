#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

long long int maxAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<long long> dp(n, -1);
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        long long rob = nums[i];
        if (i - 2 >= 0)
        {
            rob += dp[i - 2];
        }
        long long notRob = 0 + dp[i - 1];
        dp[i] = max(rob, notRob);
    }
    return dp[n - 1];
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1)
        return valueInHouse[0];

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }

    return max(maxAdjacentSum(temp1), maxAdjacentSum(temp2));
}