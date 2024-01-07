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
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }

        vector<int> dp(n, 0); //* dp[i] = number of Arithmetic Progressions that are ending at index i

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            //* check if last numbers are in AP
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = dp[i - 1] + 1; //* if we already had an AP at previous index it will also grow and we got another AP hence we do dp[i - 1] + 1
                count += dp[i];        //* ans is summation of all AP's
            }
        }
        return count;
    }
};