#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// # Tutorial - https://www.youtube.com/watch?v=xvNwoz-ufXA&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=31, https://www.youtube.com/watch?v=20v8zSo2v18

//! Unordered Map
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> prefixSumMap; // prefixSum -> freq
        prefixSumMap[prefixSum] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            count += prefixSumMap[prefixSum - k];

            // if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end())
            // {
            //     count += prefixSumMap[prefixSum - k];
            // }

            prefixSumMap[prefixSum]++;
        }
        return count;
    }
};

// # Count number of subarrays with given xor K

int subsetXOR(vector<int> arr, int N, int K)
{
    int count = 0;
    int xorSum = 0;
    unordered_map<int, int> xorSumMap; // xorSum -> freq
    xorSumMap[xorSum]++;               // we already have xorSum = 0 once
    for (int i = 0; i < N; i++)
    {
        xorSum = xorSum ^ arr[i];

        int x = xorSum ^ K;

        count += xorSumMap[x];

        xorSumMap[xorSum]++;
    }
    return count;
}