#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <cstring>
using namespace std;

//! Space Optimized Tabulation DP
int FindMaxSum(int arr[], int n)
{
 int prev = arr[0];
 int prev2 = 0;
 for (int i = 1; i < n; i++)
 {
  int rob = arr[i];
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

//! Tabulation DP -> Bottom Up Approach
int FindMaxSum(int arr[], int n)
{
 vector<int> dp(n, -1);
 dp[0] = arr[0];
 for (int i = 1; i < n; i++)
 {
  int rob = arr[i];
  if (i > 1)
  {
   rob += dp[i - 2];
  }
  int notRob = 0 + dp[i - 1];
  dp[i] = max(rob, notRob);
 }
 return dp[n - 1];
}

//! Memoization DP
int helper(int arr[], int index, vector<int> &dp)
{
 if (index == 0)
  return arr[index];

 if (index < 0)
  return 0;

 if (dp[index] != -1)
  return dp[index];

 int rob = arr[index] + helper(arr, index - 2, dp);
 int notRob = 0 + helper(arr, index - 1, dp);
 return dp[index] = max(rob, notRob);
}

// Function to find the maximum money the thief can get.
int FindMaxSum(int arr[], int n)
{
 vector<int> dp(n, -1);
 return helper(arr, n - 1, dp);
}

//! Recursion -> Top Down Approach
int helper(int arr[], int index)
{
 if (index == 0)
  return arr[index];

 if (index < 0)
  return 0;

 int rob = arr[index] + helper(arr, index - 2);
 int notRob = 0 + helper(arr, index - 1);
 return max(rob, notRob);
}

// Function to find the maximum money the thief can get.
int FindMaxSum(int arr[], int n)
{
 return helper(arr, n - 1);
}