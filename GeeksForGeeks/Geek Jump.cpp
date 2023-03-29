#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

// # Tutorial: https://www.youtube.com/watch?v=EgG3jsGoPvQ

//! Space Optimized Tabulation DP
class Solution
{
public:
 int minimumEnergy(vector<int> &height, int n)
 {
  int prev = 0;
  int secondPrev = 0;
  for (int i = 1; i < n; i++)
  {
   int oneStep = prev + abs(height[i] - height[i - 1]);
   int twoStep = INT_MAX;
   if (i > 1)
   {
    twoStep = secondPrev + abs(height[i] - height[i - 2]);
   }
   int curr = min(oneStep, twoStep);
   secondPrev = prev;
   prev = curr;
  }
  return prev;
 }
};

//! Tabulation DP -> Bottom Up Approach
int minimumEnergy(vector<int> &height, int n)
{
 vector<int> dp(n, -1);
 dp[0] = 0;
 for (int i = 1; i < n; i++)
 {
  int oneStep = dp[i - 1] + abs(height[i] - height[i - 1]);
  int twoStep = INT_MAX;
  if (i > 1)
  {
   twoStep = dp[i - 2] + abs(height[i] - height[i - 2]);
  }
  dp[i] = min(oneStep, twoStep);
 }
 return dp[n - 1];
}

//! Memoization DP
int helper(vector<int> &height, int index, vector<int> &dp)
{
 if (index == 0)
 {
  return 0;
 }

 if (dp[index] != -1)
 {
  return dp[index];
 }

 int oneStep = helper(height, index - 1, dp) + abs(height[index] - height[index - 1]);
 int twoStep = INT_MAX;
 if (index > 1)
 {
  twoStep = helper(height, index - 2, dp) + abs(height[index] - height[index - 2]);
 }

 return dp[index] = min(oneStep, twoStep);
}
int minimumEnergy(vector<int> &height, int n)
{
 vector<int> dp(n, -1);
 return helper(height, n - 1, dp);
}

//! Recursion -> Top Down Approach
int helper(vector<int> &height, int index)
{
 if (index == 0)
 {
  return 0;
 }

 int oneStep = helper(height, index - 1) + abs(height[index] - height[index - 1]);
 int twoStep = INT_MAX;
 if (index > 1)
 {
  twoStep = helper(height, index - 2) + abs(height[index] - height[index - 2]);
 }

 return min(oneStep, twoStep);
}
int minimumEnergy(vector<int> &height, int n)
{
 return helper(height, n - 1);
}