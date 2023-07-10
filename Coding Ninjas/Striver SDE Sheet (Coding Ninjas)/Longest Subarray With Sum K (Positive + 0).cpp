#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=frf7qxiN2qU

//! 2 Pointers + Greedy (only works if arr contains positive numbers and 0 only)

/*
> Time Complexity: O(N)
    * worst case O(2N) when inner while can run for N times overall
> Space Complexity: O(1)
*/

int longestSubarrayWithSumK(vector<int> nums, long long k)
{
    int left = 0, right = 0;
    long long currSum = nums[0];
    int maxLen = 0;
    while (right < nums.size())
    {
        while (left <= right && currSum > k)
        {
            currSum -= nums[left];
            left++;
        }

        if (currSum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < nums.size())
        {
            currSum += nums[right];
        }
    }
    return maxLen;
}

//! Hashing

/*
> Time Complexity:
    * Ordered Map (No Collisions): O(N * Log(N))
    * Unordered Map (No Collisions): O(N), the search time is O(1)
    *               (With Collisions): O(N^2), the search time is O(N)
> Space Complexity: O(N)
*/

#include <bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> nums, long long k)
{
    map<long long, int> prefixSumMap;
    long long prefixSum = 0;
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        if (prefixSum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        long long remainingSum = prefixSum - k;
        if (prefixSumMap.find(remainingSum) != prefixSumMap.end())
        {
            int len = i - prefixSumMap[remainingSum];
            maxLen = max(maxLen, len);
        }

        // if prefixSum already exists in hashmap don't update it's index as we need the leftmost index with sum = prefixSum in order to get the longest subarray
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end())
        {
            prefixSumMap[prefixSum] = i;
        }
    }
    return maxLen;
}

//! Better Brute Force

/*
> Time Complexity: O(N^2)
> Space Complexity: O(1)
*/

int longestSubarrayWithSumK(vector<int> nums, long long k)
{
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        long long subarraySum = 0;
        for (int j = i; j < n; j++)
        {
            subarraySum += nums[j];
            if (subarraySum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}

//! Brute Force

/*
> Time Complexity: O(N^3)
> Space Complexity: O(1)
*/

int longestSubarrayWithSumK(vector<int> nums, long long k)
{
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long subarraySum = 0;
            for (int k = i; k <= j; k++)
            {
                subarraySum += nums[k];
            }
            if (subarraySum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}
