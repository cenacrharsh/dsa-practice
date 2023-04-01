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
    int largestPerimeter(vector<int> &nums)
    {
        /*
        After sorted array, considering three last elements: (A[n-1], A[n-2], A[n-3]), if A[n-2] + A[n-3] is not > A[n - 1] then A[n-1] will never be in any three tuple that is legal triangle. So, we will remove it from our array. And the correspond with A[n - 2]...
        */

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = n - 1; i >= 2; i--)
        {
            if (nums[i - 1] + nums[i - 2] > nums[i])
            {
                return nums[i] + nums[i - 1] + nums[i - 2];
            }
        }
        return 0;
    }
};