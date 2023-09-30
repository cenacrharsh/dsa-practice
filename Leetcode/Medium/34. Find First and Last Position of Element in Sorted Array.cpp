#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=hjR1IYVx9lY&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=5

/*
> Time Complexity: O(2 * log (n) base 2)
> Space Complexity: O()
*/

//! Using plain Binary Search

class Solution
{
public:
    int firstOccurence(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                //* we'll go left to see if it occurs again
                high = mid - 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    int secondOccurence(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                //* we'll go right to see if it occurs again
                low = mid + 1;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int firstOcc = firstOccurence(nums, target);
        if (firstOcc == -1)
        {
            return {-1, -1};
        }

        int secondOcc = secondOccurence(nums, target);

        return {firstOcc, secondOcc};
    }
};

//! Using lower_bound() & upper_bound()

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        //* if target is not present in array:
        //* case 1: target > nums[n - 1] -> lb is == n
        //* case 2: target lies in array range but not actually present -> lb will point to index >= target, so nums[lb] != target
        if (lb == nums.size() || nums[lb] != target)
        {
            return {-1, -1};
        }

        //* since ub gives smallest index > target
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        return {lb, ub - 1};
    }
};