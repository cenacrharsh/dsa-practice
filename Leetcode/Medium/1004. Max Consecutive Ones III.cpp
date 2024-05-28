#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//# Tutorial: https://www.youtube.com/watch?v=3E4JBHSLpYk&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=9

//! Optimized Sliding Window

/*
> Time Complexity: O(N)
> Space Complexity: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //* longest subarray with at most k zeroes
        //* optimized sliding window we don't let window size drop below the max size we have found already as that's our ans if we don't find anything bigger than that so no point in shrinking window and then increasing it again, thus removing the inner while loop

        int left = 0, right = 0, numZeroes = 0, maxLen = INT_MIN;
        while(right < nums.size()) {
            if(nums[right] == 0) {
                numZeroes++;
            }

            if(numZeroes > k) {
                if(nums[left] == 0) {
                    numZeroes--;
                }
                left++;
            }

            if(numZeroes <= k) {
                maxLen = max(maxLen, right - left + 1);
            }
            right++;
        }
        return maxLen;
    }
};

//! Sliding Window

/*
> Time Complexity: O(N) + O(N) -> both while loops can traverse at max N
> Space Complexity: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //* longest subarray with at most k zeroes
        int left = 0, right = 0, numZeroes = 0, maxLen = INT_MIN;
        while(right < nums.size()) {
            if(nums[right] == 0) {
                numZeroes++;
            }

            while(numZeroes > k) {
                if(nums[left] == 0) {
                    numZeroes--;
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

