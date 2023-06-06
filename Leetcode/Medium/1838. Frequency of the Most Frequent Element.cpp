#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=vgBrQ0NM5vE

/*
> Time Complexity: O(n * log(n))
> Space Complexity: O(1)
*/

//! Sliding Window
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int l = 0, r = 0, maxLen = 0;
        long long total = 0;

        while (r < nums.size())
        {
            total += nums[r];

            while ((long long)nums[r] * (r - l + 1) - total > k)
            {
                total -= nums[l];
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};