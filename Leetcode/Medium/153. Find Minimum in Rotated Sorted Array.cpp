#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Using Binary Search

/*
> Time Complexity: O(log (n) base 2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        //! sorted half may or maynot contain the answer -> pick the min from sorted half and eliminate it

        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            //* if the entire search space is alredy sorted (i.e we have crossed the point of rotation) then nums[low] will always be the smallest element in that search space
            if (nums[low] <= nums[high])
            {
                ans = min(ans, nums[low]);
                break;
            }

            //* left half is sorted
            if (nums[low] <= nums[mid])
            {
                //* pick the smallest element i.e arr[low] and eliminate
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            //* right half is sorted
            else
            {
                //* pick the smallest element i.e arr[mid] and eliminate
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};