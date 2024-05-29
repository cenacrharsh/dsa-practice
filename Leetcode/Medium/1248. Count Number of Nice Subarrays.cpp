#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=j_QOv9OT9Og&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=10

//! Sliding Window

/*
> Time Complexity: O(2 * 2N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int helper(vector<int>& nums, int goal) {
        if(goal < 0) {
            return 0;
        }
        int left = 0, right = 0, count = 0, sum = 0;
        while(right < nums.size()) {
            sum += nums[right] % 2; //* if odd +1 else +0

            while(sum > goal) {
                sum -= nums[left] % 2; //* if odd -1 else -0
                left++;
            }

            count += (right - left + 1);
            right++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        //* same as 930. Binary Subarrays With Sum
        //* treat odd numbers as 1 and even numbers as 0, then sum(k) == sum(<=k) - sum(<=k-1)
        return helper(nums, k) - helper(nums, k - 1);
    }
};

