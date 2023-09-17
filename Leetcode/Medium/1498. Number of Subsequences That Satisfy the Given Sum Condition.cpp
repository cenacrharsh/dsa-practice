#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=wwDTU32JTQg

/*
If you pin left element, from [left + 1, right], you can either choose or not choose each element, so 2 ways for each element. There are total (right - left) number of elements from [left + 1, right]. So, 2 x 2 x 2 x ... (right - left) times ==> 2 ^ (right - left).
*/

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