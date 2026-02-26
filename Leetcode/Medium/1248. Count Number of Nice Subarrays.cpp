#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Sliding Window

/*
> Time Complexity: O(2 * 2N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int helper(vector<int>& nums, int k) {
        if(k < 0) {
            return 0;
        }

        int left = 0, right = 0, count = 0, sum = 0;
        while(right < nums.size()) {
            sum += (nums[right] % 2); //* %2 will give 1 for odd numbers and 0 for even numbers
            while(sum > k) {
                sum -= (nums[left] % 2);
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //* same as 930. Binary Subarrays With Sum
        //* treat odd numbers as 1 and even numbers as 0 eg. [1,5,2,3,1] -> [1,1,0,1,1], then sum(k) == sum(<=k) - sum(<=k-1)
        return helper(nums, k) - helper(nums, k - 1);
    }
};

