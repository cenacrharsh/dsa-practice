#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

class Solution
{
public:
 int findClosestNumber(vector<int> &nums)
 {
  int res = nums[0];
  for (auto x : nums)
  {
   if (abs(x) < abs(res) || abs(x) == abs(res) && x > res)
    res = x;
  }
  return res;
 }
};

//! Contest Solution

class Solution
{
public:
 int findClosestNumber(vector<int> &nums)
 {
  int minDistance = INT_MAX;
  int num = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
   int dist = abs(nums[i]);
   if (dist == minDistance)
   {
    if (nums[i] > num)
    {
     minDistance = dist;
     num = nums[i];
    }
   }
   else if (dist < minDistance)
   {
    minDistance = dist;
    num = nums[i];
   }
  }
  return num;
 }
};