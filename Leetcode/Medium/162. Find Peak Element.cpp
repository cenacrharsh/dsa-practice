#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Binary Search

/*
> Time Complexity: O(log (n) base 2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        //! for elimination we see the curves
        //! on an increasing curve, peak always lies to the right
        //! on a decreasing curve, peak always lies to the left

        //* edge cases
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            //* we are on an increasing curve, eliminate left half
            else if (nums[mid] > nums[mid - 1])
            {
                low = mid + 1;
            }
            //* we are on a decreasing curve, eliminate right half
            //- it also solves our problem in case of multiple peaks, in which we might encounter a case where mid lies on minima i.e < both left and right values, eg. [1, 5, 1, 2, 1], so we can either use else if for decreasing curve and then use separate else for minima where we can eliminate either half as both halves will contain a peak(maxima) or handle both together in single else
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

//! Linear Search

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i == 0 || nums[i] > nums[i - 1]) &&
                (i == n - 1 || nums[i] > nums[i + 1]))
            {
                return i;
            }
        }
        return -1;
    }
};