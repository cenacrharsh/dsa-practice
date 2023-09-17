#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! 1 Traversals
class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool isIncreasing = true;
        bool isDecreasing = true;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                isIncreasing = false;
            }
            if (nums[i] > nums[i + 1])
            {
                isDecreasing = false;
            }
        }
        return isIncreasing || isDecreasing;
    }
};

//! 2 Traversals
class Solution
{
public:
    bool isIncreasing(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    bool isDecreasing(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int> &nums)
    {
        return isIncreasing(nums) || isDecreasing(nums);
    }
};