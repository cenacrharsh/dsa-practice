#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=7wYGbV_LsX4&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=24

//! Sliding Window

/*
> Time Complexity: O(2 * (2N))
> Space Complexity: O(2 * N)
*/

class Solution {
public:
    int helper(vector<int>& nums, int target) {
        int left = 0, right = 0, count = 0;
        unordered_map<int, int> freq; //* num->freq
        while(right < nums.size()) {
            freq[nums[right]]++;
            while(freq.size() > target) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count = count + (right - left + 1);
            right++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //* num(subarrays with k diff. integers) = num(subarrays with <= k diff integers) - num(subarrays with <= [k - 1] different integers)
        return helper(nums, k) - helper(nums, k - 1);
    }
};