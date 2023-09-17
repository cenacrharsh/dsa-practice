#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=LSFcmgq0HYY

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int left, right, total;
        int oddSum = 0, evenSum = 0;
        for (int i = 0; i < n; i++)
        {
            left = i + 1;  // subarrays to left
            right = n - i; // subarrays to right => ((n-1) - i) + 1 => 1 for overall subarray containing all elements
            total = left * right;
            oddSum += ((total + 1) / 2) * arr[i];
            evenSum += (total / 2) * arr[i];
        }
        return oddSum;
    }
};