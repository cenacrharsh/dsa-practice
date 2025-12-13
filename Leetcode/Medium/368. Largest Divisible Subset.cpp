#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        // since we can give the answer in any order we want, we can sort the
        // numsay, once sorted if a,b means a % b, then comes c and if b % c then
        // since it's in sorted manner it's fixed a % c => basically gets converted to print LIS

        int n = nums.size();
        vector<int> dp(n, 1), hash(n, 0);
        int maxLen = 1;
        int lastIndex = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis;
        lis.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            lis.push_back(nums[lastIndex]);
        }
        reverse(lis.begin(), lis.end());
        return lis;
    }
};