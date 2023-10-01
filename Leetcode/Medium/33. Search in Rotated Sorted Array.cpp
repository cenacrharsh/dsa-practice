#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=5qGrJbHhqFs&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=10

/*
> Time Complexity: O(log (n) base 2)
> Space Complexity: O()
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //! key is to identify the sorted half

        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            //* left half is sorted
            if (nums[low] <= nums[mid])
            {
                //* figure out if element lies in left sorted half
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            //* right half is sorted
            else
            {
                //* figure out if element lies in right sorted half
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};