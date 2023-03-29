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
 int rob(vector<int> &nums)
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
};

//! Tabulation DP -> Bottom Up Approach

//! Memoization DP

//! Recursion -> Top Down Approach
