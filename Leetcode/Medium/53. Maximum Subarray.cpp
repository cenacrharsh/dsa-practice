#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Approach - 1
class Solution
{
public:
 int maxSubArray(vector<int> &nums)
 {
  int currMax = 0;
  int maxSubArr = INT_MIN;
  for (auto num : nums)
  {
   currMax = max(num, currMax + num);
   maxSubArr = max(maxSubArr, currMax);
  }
  return maxSubArr;
 }
};

//! Approach - 2
class Solution
{
public:
 int maxSubArray(vector<int> &nums)
 {
  int n = nums.size();
  int currSum = 0;
  int maxSum = INT_MIN;
  for (int i = 0; i < n; i++)
  {
   currSum += nums[i];
   maxSum = max(maxSum, currSum);
   if (currSum < 0)
   {
    currSum = 0;
   }
  }
  return maxSum;
 }
};