#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Using Binary Search

/*
> Time Complexity: O(log (n) base 2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        //! to decide which half to eliminate we look at index of pair (N, N)
        //! (even, odd) -> element is in right half
        //! (odd, even) -> element is in left half

        //* edge cases
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            //* single element found
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }

            /* elimination */
            //* (even, odd) -> we are on the left half of single element, eliminate left half
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            {
                low = mid + 1;
            }
            //* we are on the right half of single element, eliminate right half
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

//! Using XOR

/*
> Time Complexity: O(n)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int sum = 0;
        for (int i : nums)
        {
            sum ^= i;
        }
        return sum;
    }
};