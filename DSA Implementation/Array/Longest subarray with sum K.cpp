#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Optimal => Works for all cases, +ve -ve and 0, The most optimal solution if -ves exist

/*
> Time Complexity: O(N * 1) => if unordered map, if more collisions then worst O(N^2) => O(N * Log N). if ordred map is used, no collisions
> Space Complexity: O(N)
*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        //* at index i we find if there exists a subarray with sum k and with element at index i as the last element, which basically means if sum uptil index i is x then for there to be a subarray with sum k and ending at index i there needs to exist a index < i at which the sum = x - k, basically (x - k) + k = sum x at index i

        unordered_map<int, int> mp;
        mp[0] = -1;
        int maxLen = INT_MIN;
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int target = prefixSum - k;
            if (mp.find(target) != mp.end())
            {
                // cout << "target " << target << " " << mp[target] << endl;
                maxLen = max(maxLen, i - mp[target]);
            }

            //* since we need longest length, if prefixSum comes again we should not update it in the hash map so that we always get the leftmost instance of prefixSum
            if (mp.find(prefixSum) == mp.end())
            {
                mp[prefixSum] = i;
            }
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};

//! Optimal => 2 Pointers + Greedy Approach => Works only for +ve numbers and 0's

/*
> Time Complexity: O(N + N) => Inner loop doesn't always run for N, overall in the entire iteration it might run of N times
> Space Complexity: O(1)
*/

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        int maxLen = INT_MIN;
        int left = 0, right = 0;
        int currSum = nums[0];
        while (right < nums.size())
        {
            while (left <= right && currSum > k)
            {
                currSum -= nums[left];
                left++;
            }

            if (currSum == k)
            {
                maxLen = max(maxLen, (right - left + 1));
            }

            right++;
            if (right < nums.size())
            {
                currSum += nums[right];
            }
        }
        return maxLen == INT_MIN ? 0 : maxLen;
    }
};

//! Brute Force, Generate all subarrays in 3 loops then 2 loops

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/