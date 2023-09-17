#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=frf7qxiN2qU

/*
> Time Complexity:
    * Ordered Map (No Collisions): O(N * Log(N))
    * Unordered Map (No Collisions): O(N), the search time is O(1)
    *               (With Collisions): O(N^2), the search time is O(N)
> Space Complexity: O(N)
*/

//! Hashing (optimal solution if array contains negative numbers)

int getLongestSubarray(vector<int> &nums, int k)
{
    unordered_map<long long, int> prefixSumMap;
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

        //* if prefixSum already exists in hashmap don't update it's index as we need the leftmost index with sum = prefixSum in order to get the longest subarray
        if (prefixSumMap.find(prefixSum) == prefixSumMap.end())
        {
            prefixSumMap[prefixSum] = i;
        }
    }
    return maxLen;
}