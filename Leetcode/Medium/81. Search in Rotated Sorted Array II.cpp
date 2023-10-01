#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=w2G2W8l__pc&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=6

/*
> Time Complexity: O(n / 2) in worst case if many duplicates, O(log (n) base 2) in avg case
> Space Complexity: O()
*/

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        //! key difference is due to to repeating values we can't use prev logic to decide which half is sorted
        //! eg. [3, 1, 2, 3, 3, 3, 3] -> arr[low] = arr[mid] = arr[high]
        //! Solution: since we know arr[mid] != target so we elimate arr[low] & arr[high]

        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return true;
            }

            //* check if arr[low] = arr[mid] = arr[high]
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue; //* we keep doing this unless we get different values
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
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
        return false;
    }
};