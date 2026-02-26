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

class Solution
{
public:
    int countSubarrayWithGivenSum(vector<int> &nums, int goal)
    {
        if (goal < 0)
        {
            return 0;
        }
        int left = 0, right = 0, sum = 0, count = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum > goal)
            {
                sum -= nums[left];
                left++;
            }
            count += (right - left + 1); //* all subarrays ending at index right are eligible
            right++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        //* due to the presence of 0's in the array the subarray sum would not change in case of moving indexes so normal 2 pointers won't work
        //* we count all the subarray <= goal
        //* ans = f(count of all subarrays <= goal) - f(count of all subarrays <= goal - 1)

        return countSubarrayWithGivenSum(nums, goal) - countSubarrayWithGivenSum(nums, goal - 1);
    }
};

//! Hashmap + 2 Pointers

/*
> Time Complexity: O(N)
> Space Complexity: O(N)
*/

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        //* boils down to count subarray with subarray sum == k
        //* due to array being binary further optimization is possible

        unordered_map<int, int> mp;
        int count = 0, prefixSum = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            int target = prefixSum - goal;
            if (mp.find(target) != mp.end())
            {
                count += mp[target];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};

//! Brute Force

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int tempSum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                tempSum += nums[j];
                if (tempSum == goal)
                {
                    count++;
                }
            }
        }
        return count;
    }
};