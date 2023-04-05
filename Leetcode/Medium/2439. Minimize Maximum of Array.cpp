#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=xDN7LSSmvDU

//! Using Prefix Sum

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long long ans = nums[0];
        long long prefixSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            if (nums[i] > ans)
            {
                long long avg = prefixSum / (i + 1);
                if (avg >= ans)
                {
                    // checking if avg has decimal part in it
                    if ((prefixSum % (i + 1)))
                    {
                        ans = avg + 1;
                    }
                    else
                    {
                        ans = avg;
                    }
                }
            }
        }
        return ans;
    }
};