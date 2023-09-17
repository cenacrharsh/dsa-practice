#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Binary Search
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        //* apply binary search from 0->n-1, calc mid and see if it's a peak element, if not then if prev element is > mid we move to left side of mid and if next element is greater than mid then we move to right side of mid
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if ((mid == 0 || nums[mid - 1] <= nums[mid]) &&
                (mid == n - 1 || nums[mid + 1] <= nums[mid]))
            {
                ans = mid;
                break;
            }
            else if (mid > 0 && nums[mid - 1] > nums[mid])
            {
                high = mid - 1;
            }
            else if (mid < n - 1 && nums[mid + 1] > nums[mid])
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};