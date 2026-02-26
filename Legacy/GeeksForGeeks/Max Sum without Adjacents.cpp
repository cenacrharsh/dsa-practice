#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP
int findMaxSum(int *arr, int n)
{
 int prev = arr[0];
 int prev2 = 0;
 for (int i = 1; i < n; i++)
 {
  int pick = arr[i];
  if (i > 1)
  {
   pick += prev2;
  }
  int notPick = 0 + prev;
  int curr = max(pick, notPick);
  prev2 = prev;
  prev = curr;
 }
 return prev;
}

//! Tabulation DP -> Bottom Up Approach
int findMaxSum(int *arr, int n)
{
 if (n == 1)
  return arr[0];
 vector<int> dp(n, -1);
 dp[0] = arr[0];
 for (int i = 1; i < n; i++)
 {
  int pick = arr[i];
  if (i > 1)
  {
   pick += dp[i - 2];
  }
  int notPick = 0 + dp[i - 1];
  dp[i] = max(pick, notPick);
 }
 return dp[n - 1];
}

//! Memoization DP
int helper(int *arr, int index, vector<int> &dp)
{
 if (index < 0)
  return 0;
 // if we reach index 0, means we not picked index 1, so to maximize sum we pick index 0
 if (index == 0)
  return arr[0];

 if (dp[index] != -1)
 {
  return dp[index];
 }

 int pick = arr[index] + helper(arr, index - 2, dp);
 int notPick = 0 + helper(arr, index - 1, dp);

 return dp[index] = max(pick, notPick);
}

// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n)
{
 vector<int> dp(n, -1);
 return helper(arr, n - 1, dp);
}

//! Recursion -> Top Down Approach
int helper(int *arr, int index)
{
 if (index < 0)
  return 0;
 // if we reach index 0, means we not picked index 1, so to maximize sum we pick index 0
 if (index == 0)
  return arr[0];

 int pick = arr[index] + helper(arr, index - 2);
 int notPick = 0 + helper(arr, index - 1);

 return max(pick, notPick);
}

// calculate the maximum sum with out adjacent
int findMaxSum(int *arr, int n)
{
 return helper(arr, n - 1);
}