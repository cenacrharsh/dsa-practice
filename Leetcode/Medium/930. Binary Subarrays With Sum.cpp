#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=XnMdNUkX6VM&list=PLgUwDviBIf0q7vrFA_HEWcqRqMpCXzYAL&index=9

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
            sum += nums[right];

            while(sum > goal) {
                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //* sum(k) == sum(<=k) - sum(<=k-1)
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};

//! Using Hashmap

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[prefixSum] = 1;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            count += prefixSumMap[prefixSum - goal];
            prefixSumMap[prefixSum]++;
        }
        return count;
    }
};