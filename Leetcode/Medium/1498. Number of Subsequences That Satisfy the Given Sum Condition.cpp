#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using 2 pointer

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int mod = 1e9 + 7;

        //* no. of subsequences = 2^n

        // Precompute the value of 2 to the power of each value
        // 2^0 = 1, 2^1 = 2, 2^2 = 4, 2^3 = 8...
        vector<int> power(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            if (nums[l] + nums[r] > target)
            {
                r--;
            }
            else
            {
                ans = (ans + power[r - l]) % mod;
                l++;
            }
        }
        return ans;
    }
};