#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=3WaxQMELSkw

//! Space Optimized Tabulation DP
class Solution
{
public:
 int maxAdjacentSum(vector<int> &nums)
 {
  int prev = nums[0];
  int prev2 = 0;
  for (int i = 0; i < nums.size(); i++)
  {
   int rob = nums[i];
   if (i > 1)
   {
    rob += prev2;
   }
   int notRob = 0 + prev;
   int curr = max(rob, notRob);
   prev2 = prev;
   prev = curr;
  }
  return prev;
 }

 int rob(vector<int> &nums)
 {
  if (nums.size() == 1)
  {
   return nums[0];
  }
  vector<int> temp1, temp2;
  for (int i = 0; i < nums.size(); i++)
  {
   if (i != 0)
    temp1.push_back(nums[i]);
   if (i != nums.size() - 1)
    temp2.push_back(nums[i]);
  }
  return max(maxAdjacentSum(temp1), maxAdjacentSum(temp2));
 }
};

//! Tabulation DP -> Bottom Up Approach

//! Memoization DP

//! Recursion -> Top Down Approach