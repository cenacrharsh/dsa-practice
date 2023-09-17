#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

//! Approach 1 -> 2 traversals
class Solution
{
public:
 int pivotIndex(vector<int> &nums)
 {
  int totalSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   totalSum += nums[i];
  }
  int leftSum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   if (i != 0)
   {
    leftSum += nums[i - 1];
   }
   if ((totalSum - leftSum - nums[i]) == leftSum)
   {
    return i;
   }
  }
  return -1;
 }
};

//! Approach 2 -> 3 traversals
class Solution
{
public:
 int pivotIndex(vector<int> &nums)
 {
  int n = nums.size();
  int prefixSum[n], suffixSum[n];
  // prefixSum contains sum of elements till i - 1
  prefixSum[0] = 0;
  for (int i = 1; i < n; i++)
  {
   prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
  }
  // suffixSum contains sum of elements from i + 1
  suffixSum[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--)
  {
   suffixSum[i] = suffixSum[i + 1] + nums[i + 1];
  }
  int ans = -1;
  for (int i = 0; i < n; i++)
  {
   if (prefixSum[i] == suffixSum[i])
   {
    ans = i;
    break;
   }
  }
  return ans;
 }
};